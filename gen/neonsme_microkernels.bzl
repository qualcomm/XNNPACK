"""
Microkernel filenames lists for neonsme.

Auto-generated file. Do not edit!
  Generator: tools/update-microkernels.py
"""

PROD_NEONSME_MICROKERNEL_SRCS = [
    "src/pf32-gemm/pf32-gemm-32x32-minmax-neonsme.c",
    "src/pf32-gemm/pf32-igemm-32x32-minmax-neonsme.c",
    "src/pqs8-qc8w-gemm/pqs8-qc8w-gemm-32x32-minmax-neonsme.c",
    "src/qs8-qc8w-igemm/qs8-qc8w-igemm-32x32-minmax-fp32-neonsme.c",
]

NON_PROD_NEONSME_MICROKERNEL_SRCS = [
]

ALL_NEONSME_MICROKERNEL_SRCS = PROD_NEONSME_MICROKERNEL_SRCS + NON_PROD_NEONSME_MICROKERNEL_SRCS
