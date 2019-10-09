//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-19, Lawrence Livermore National Security, LLC
// and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//////////////////////////////////////////////////////////////////////////////
#include "RAJA/RAJA.hpp"

template <typename T>
T *allocate(std::size_t size)
{
  T *ptr;
#if defined(RAJA_ENABLE_CUDA)
  cudaErrchk(
      cudaMallocManaged((void **)&ptr, sizeof(T) * size, cudaMemAttachGlobal));
#else
  ptr = new T[size];
#endif
  return ptr;
}

template <typename T>
void deallocate(T *&ptr)
{
  if (ptr) {
#if defined(RAJA_ENABLE_CUDA)
    cudaErrchk(cudaFree(ptr));
#else
    delete[] ptr;
#endif
    ptr = nullptr;
  }
}

int main(int argc, char *argv[])
{

#if defined(RAJA_ENABLE_CUDA)
  using policy = RAJA::cuda_exec;
#elif defined(RAJA_ENABLE_OPENMP)
  using policy = RAJA::omp_parallel_for_exec;
#else
  using policy = RAJA::seq_exec;
#endif

  constexpr int N = 1000000;

  int *a = allocate<int>(N);
  int *b = allocate<int>(N);
  int *c = allocate<int>(N);

  for (int i = 0; i < N; ++i) {
    a[i] = -i;
    b[i] = i;
  }

  RAJA::forall<policy>(RAJA::RangeSegment(0, N), [=] RAJA_HOST_DEVICE (int i) { 
    c[i] = a[i] + b[i]; 
  });

  deallocate(a);
  deallocate(b);
  deallocate(c);
}
