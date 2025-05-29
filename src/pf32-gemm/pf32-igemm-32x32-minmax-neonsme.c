#include <stddef.h>

#include "kai/kai_common.h"
#include "kai/ukernels/matmul/matmul_clamp_f32_f32p_f32p/kai_matmul_clamp_f32_f32p2vlx1_f32p2vlx1biasf32_sme2_mopa.h"
#include "kai/ukernels/matmul/matmul_clamp_f32_f32p_f32p/kai_matmul_clamp_f32_f32p2vlx1_f32p2vlx1biasf32_sme1_mopa.h"
#include "kai/ukernels/matmul/imatmul_clamp_f32_f32p_f32p/kai_imatmul_clamp_f32_f32p2vlx1_f32p2vlx1b_2vlx2vl_sme2_mopa.h"
#include "kai/ukernels/matmul/pack/kai_lhs_imatmul_pack_x32p2vlx1_x32p_sme.h"
#include "xnnpack/igemm.h"
#include "xnnpack/math.h"
#include "xnnpack/allocator.h"
#include <arm_neon.h>
#include <stdio.h> 
size_t xnn_pf32_igemm_minmax_fp32_ukernel_32x32__neonsme_get_mr(void)
{
  return kai_get_m_step_matmul_clamp_f32_f32p2vlx1_f32p2vlx1biasf32_sme1_mopa();
}

size_t xnn_pf32_igemm_minmax_fp32_ukernel_32x32__neonsme_get_nr(void)
{
  return kai_get_n_step_matmul_clamp_f32_f32p2vlx1_f32p2vlx1biasf32_sme1_mopa();
}

void xnn_pf32_igemm_minmax_fp32_ukernel_32x32__neonsme(
  size_t mr,
  size_t nc,
  size_t kc,
  size_t ks,
  const float** a,
  const float*  w,
  float*  c,
  size_t cm_stride,
  size_t cn_stride,
  size_t a_offset,
  const float * zero,
  const union xnn_f32_minmax_params params[XNN_RESTRICT XNN_MIN_ELEMENTS(1)])
{
  const size_t kai_mr = xnn_pf32_igemm_minmax_fp32_ukernel_32x32__neonsme_get_mr();
  const size_t k_chunk_count = ks / sizeof(float*) / kai_mr;
  const size_t k_chunk_length = kc / sizeof(float);
  const size_t kai_kr = 1;
  const size_t k = k_chunk_count * round_up(k_chunk_length, kai_kr);
  
  const size_t packed_lhs_size =
    kai_get_lhs_packed_size_lhs_imatmul_pack_x32p2vlx1_x32p_sme(mr, k_chunk_count, k_chunk_length);

  void *packed_lhs = xnn_allocate_memory(packed_lhs_size);
  
  /* Pack LHS */  
  kai_run_lhs_imatmul_pack_x32p2vlx1_x32p_sme(mr, k_chunk_count, k_chunk_length, a, a_offset, zero, packed_lhs);

  /* Core GEMM kernel */
  kai_run_matmul_clamp_f32_f32p2vlx1_f32p2vlx1biasf32_sme1_mopa(
    mr, nc, k, packed_lhs, w, c, cm_stride, sizeof(float),
    params->scalar.min, params->scalar.max);

  xnn_release_memory(packed_lhs);
}
