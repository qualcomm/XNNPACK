// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv/unipass-neon.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>
#include <arm_sve.h>
#include <stdio.h>

#include "xnnpack/dwconv.h"


/* NOTE:::: Neon and SME are renamed for easy integration */


void xnn_f32_dwconv_minmax_ukernel_9p8c__neonfma_sme(
    size_t channels,
    size_t output_width,
    const float** input,
    const float* weights,
    float* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const float* zero,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(channels != 0);
  assert(output_width != 0);

  const float32x4_t vmax = vdupq_n_f32(params->scalar.max);
  const float32x4_t vmin = vdupq_n_f32(params->scalar.min);
  do {
    const float* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const float*) ((uintptr_t) i0 + input_offset);
    }
    const float* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const float*) ((uintptr_t) i1 + input_offset);
    }
    const float* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const float*) ((uintptr_t) i2 + input_offset);
    }
    const float* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const float*) ((uintptr_t) i3 + input_offset);
    }
    const float* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const float*) ((uintptr_t) i4 + input_offset);
    }
    const float* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const float*) ((uintptr_t) i5 + input_offset);
    }
    const float* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const float*) ((uintptr_t) i6 + input_offset);
    }
    const float* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const float*) ((uintptr_t) i7 + input_offset);
    }
    const float* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const float*) ((uintptr_t) i8 + input_offset);
    }

    input = (const float**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const float* w = weights;
    for (; c >= 8; c -= 8) {
      float32x4_t vacc0123p0 = vld1q_f32(w); w += 4;
      float32x4_t vacc4567p0 = vld1q_f32(w); w += 4;


      const float32x4_t vi0x0123 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vi0x4567 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vk0x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk0x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi0x0123, vk0x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi0x4567, vk0x4567);

      const float32x4_t vi1x0123 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vi1x4567 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vk1x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk1x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi1x0123, vk1x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi1x4567, vk1x4567);

      const float32x4_t vi2x0123 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vi2x4567 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vk2x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk2x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi2x0123, vk2x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi2x4567, vk2x4567);

      const float32x4_t vi3x0123 = vld1q_f32(i3); i3 += 4;
      const float32x4_t vi3x4567 = vld1q_f32(i3); i3 += 4;
      const float32x4_t vk3x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk3x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi3x0123, vk3x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi3x4567, vk3x4567);

      const float32x4_t vi4x0123 = vld1q_f32(i4); i4 += 4;
      const float32x4_t vi4x4567 = vld1q_f32(i4); i4 += 4;
      const float32x4_t vk4x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk4x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi4x0123, vk4x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi4x4567, vk4x4567);

      const float32x4_t vi5x0123 = vld1q_f32(i5); i5 += 4;
      const float32x4_t vi5x4567 = vld1q_f32(i5); i5 += 4;
      const float32x4_t vk5x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk5x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi5x0123, vk5x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi5x4567, vk5x4567);

      const float32x4_t vi6x0123 = vld1q_f32(i6); i6 += 4;
      const float32x4_t vi6x4567 = vld1q_f32(i6); i6 += 4;
      const float32x4_t vk6x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk6x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi6x0123, vk6x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi6x4567, vk6x4567);

      const float32x4_t vi7x0123 = vld1q_f32(i7); i7 += 4;
      const float32x4_t vi7x4567 = vld1q_f32(i7); i7 += 4;
      const float32x4_t vk7x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk7x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi7x0123, vk7x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi7x4567, vk7x4567);

      const float32x4_t vi8x0123 = vld1q_f32(i8); i8 += 4;
      const float32x4_t vi8x4567 = vld1q_f32(i8); i8 += 4;
      const float32x4_t vk8x0123 = vld1q_f32(w); w += 4;
      const float32x4_t vk8x4567 = vld1q_f32(w); w += 4;
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi8x0123, vk8x0123);
      vacc4567p0 = vfmaq_f32(vacc4567p0, vi8x4567, vk8x4567);


      float32x4_t vacc0123 = vmaxq_f32(vacc0123p0, vmin);
      float32x4_t vacc4567 = vmaxq_f32(vacc4567p0, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);
      vacc4567 = vminq_f32(vacc4567, vmax);

      vst1q_f32(output, vacc0123); output += 4;
      vst1q_f32(output, vacc4567); output += 4;
    }
    for (; c >= 4; c -= 4) {
      float32x4_t vacc0123p0 = vld1q_f32(w); w += 4;


      const float32x4_t vi0x0123 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vk0x0123 = vld1q_f32(w + 4);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi0x0123, vk0x0123);

      const float32x4_t vi1x0123 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vk1x0123 = vld1q_f32(w + 12);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi1x0123, vk1x0123);

      const float32x4_t vi2x0123 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vk2x0123 = vld1q_f32(w + 20);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi2x0123, vk2x0123);

      const float32x4_t vi3x0123 = vld1q_f32(i3); i3 += 4;
      const float32x4_t vk3x0123 = vld1q_f32(w + 28);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi3x0123, vk3x0123);

      const float32x4_t vi4x0123 = vld1q_f32(i4); i4 += 4;
      const float32x4_t vk4x0123 = vld1q_f32(w + 36);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi4x0123, vk4x0123);

      const float32x4_t vi5x0123 = vld1q_f32(i5); i5 += 4;
      const float32x4_t vk5x0123 = vld1q_f32(w + 44);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi5x0123, vk5x0123);

      const float32x4_t vi6x0123 = vld1q_f32(i6); i6 += 4;
      const float32x4_t vk6x0123 = vld1q_f32(w + 52);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi6x0123, vk6x0123);

      const float32x4_t vi7x0123 = vld1q_f32(i7); i7 += 4;
      const float32x4_t vk7x0123 = vld1q_f32(w + 60);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi7x0123, vk7x0123);

      const float32x4_t vi8x0123 = vld1q_f32(i8); i8 += 4;
      const float32x4_t vk8x0123 = vld1q_f32(w + 68);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi8x0123, vk8x0123);


      float32x4_t vacc0123 = vmaxq_f32(vacc0123p0, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);

      vst1q_f32(output, vacc0123); output += 4;
    }
    if XNN_UNLIKELY(c != 0) {
      float32x4_t vacc0123p0 = vld1q_f32(w);


      const float32x4_t vi0x0123 = vld1q_f32(i0);
      const float32x4_t vk0x0123 = vld1q_f32(w + 8);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi0x0123, vk0x0123);

      const float32x4_t vi1x0123 = vld1q_f32(i1);
      const float32x4_t vk1x0123 = vld1q_f32(w + 16);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi1x0123, vk1x0123);

      const float32x4_t vi2x0123 = vld1q_f32(i2);
      const float32x4_t vk2x0123 = vld1q_f32(w + 24);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi2x0123, vk2x0123);

      const float32x4_t vi3x0123 = vld1q_f32(i3);
      const float32x4_t vk3x0123 = vld1q_f32(w + 32);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi3x0123, vk3x0123);

      const float32x4_t vi4x0123 = vld1q_f32(i4);
      const float32x4_t vk4x0123 = vld1q_f32(w + 40);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi4x0123, vk4x0123);

      const float32x4_t vi5x0123 = vld1q_f32(i5);
      const float32x4_t vk5x0123 = vld1q_f32(w + 48);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi5x0123, vk5x0123);

      const float32x4_t vi6x0123 = vld1q_f32(i6);
      const float32x4_t vk6x0123 = vld1q_f32(w + 56);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi6x0123, vk6x0123);

      const float32x4_t vi7x0123 = vld1q_f32(i7);
      const float32x4_t vk7x0123 = vld1q_f32(w + 64);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi7x0123, vk7x0123);

      const float32x4_t vi8x0123 = vld1q_f32(i8);
      const float32x4_t vk8x0123 = vld1q_f32(w + 72);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi8x0123, vk8x0123);


      float32x4_t vacc0123 = vmaxq_f32(vacc0123p0, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);

      float32x2_t vacc01 = vget_low_f32(vacc0123);
      if (c & 2) {
        vst1_f32(output, vacc01); output += 2;
        vacc01 = vget_high_f32(vacc0123);
      }
      if (c & 1) {
        vst1_lane_f32(output, vacc01, 0); output += 1;
      }
    }

    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}


void xnn_f32_dwconv_minmax_ukernel_9p8c__neonfma(
    size_t channels,
    size_t output_width,
    const float** input,
    const float* weights,
    float* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    const float* zero,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{

  assert(channels != 0);
  assert(output_width != 0);

  const float32x4_t vmax = vdupq_n_f32(params->scalar.max);
  const float32x4_t vmin = vdupq_n_f32(params->scalar.min);
  do {
    const float* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const float*) ((uintptr_t) i0 + input_offset);
    }
    const float* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const float*) ((uintptr_t) i1 + input_offset);
    }
    const float* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const float*) ((uintptr_t) i2 + input_offset);
    }
    const float* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const float*) ((uintptr_t) i3 + input_offset);
    }
    const float* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const float*) ((uintptr_t) i4 + input_offset);
    }
    const float* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const float*) ((uintptr_t) i5 + input_offset);
    }
    const float* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const float*) ((uintptr_t) i6 + input_offset);
    }
    const float* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const float*) ((uintptr_t) i7 + input_offset);
    }
    const float* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const float*) ((uintptr_t) i8 + input_offset);
    }

    input = (const float**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const float* w = weights;


__asm__ volatile (
    "SMSTART\n"
    ::: "memory",
        // Predicate registers
        "p0", "p1", "p2", "p3", "p4", "p5", "p6", "p7",
        "p8", "p9", "p10", "p11", "p12", "p13", "p14", "p15",
        // Vector registers
        "z0", "z1", "z2", "z3", "z4", "z5", "z6", "z7",
        "z8", "z9", "z10", "z11", "z12", "z13", "z14", "z15",
        "z16", "z17", "z18", "z19", "z20", "z21", "z22", "z23",
        "z24", "z25", "z26", "z27", "z28", "z29", "z30", "z31"
);


    svbool_t ps = svwhilelt_b32(0, 8);

    const svfloat32_t vmax_sve = svdup_f32(params->scalar.max);
    const svfloat32_t vmin_sve = svdup_f32(params->scalar.min);

    for (; c >= 8; c -= 8) {
      svfloat32_t vacc0123p0 = svld1(ps,w); w += 8;

      const svfloat32_t vi0x0123 = svld1(ps,i0); i0 += 8;
      const svfloat32_t vk0x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi0x0123, vk0x0123);

      const svfloat32_t vi1x0123 = svld1(ps,i1); i1 += 8;
      const svfloat32_t vk1x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi1x0123, vk1x0123);

      const svfloat32_t vi2x0123 = svld1(ps,i2); i2 += 8;
      const svfloat32_t vk2x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi2x0123, vk2x0123);

      const svfloat32_t vi3x0123 = svld1(ps,i3); i3 += 8;
      const svfloat32_t vk3x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi3x0123, vk3x0123);\

      const svfloat32_t vi4x0123 = svld1(ps,i4); i4 += 8;
      const svfloat32_t vk4x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi4x0123, vk4x0123);

      const svfloat32_t vi5x0123 = svld1(ps,i5); i5 += 8;
      const svfloat32_t vk5x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi5x0123, vk5x0123);

      const svfloat32_t vi6x0123 = svld1(ps,i6); i6 += 8;
      const svfloat32_t vk6x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi6x0123, vk6x0123);

      const svfloat32_t vi7x0123 = svld1(ps,i7); i7 += 8;
      const svfloat32_t vk7x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi7x0123, vk7x0123);

      const svfloat32_t vi8x0123 = svld1(ps,i8); i8 += 8;
      const svfloat32_t vk8x0123 = svld1(ps,w); w += 8;
      vacc0123p0 = svmla_m(ps, vacc0123p0, vi8x0123, vk8x0123);

      svfloat32_t vacc0123 = svmax_z(ps, vacc0123p0, vmin_sve);
      vacc0123 = svmin_z(ps, vacc0123, vmax_sve);

      svst1(ps, output, vacc0123); output += 8;
    }
	
__asm__ volatile (
    "SMSTOP\n"
    ::: "memory",
        // Predicate registers
        "p0", "p1", "p2", "p3", "p4", "p5", "p6", "p7",
        "p8", "p9", "p10", "p11", "p12", "p13", "p14", "p15",
        // Vector registers
        "z0", "z1", "z2", "z3", "z4", "z5", "z6", "z7",
        "z8", "z9", "z10", "z11", "z12", "z13", "z14", "z15",
        "z16", "z17", "z18", "z19", "z20", "z21", "z22", "z23",
        "z24", "z25", "z26", "z27", "z28", "z29", "z30", "z31"
);

    svbool_t pg = svwhilelt_b32(0, 8);
    for (; c >= 4; c -= 4) {
      float32x4_t vacc0123p0 = vld1q_f32(w); w += 4;


      const float32x4_t vi0x0123 = vld1q_f32(i0); i0 += 4;
      const float32x4_t vk0x0123 = vld1q_f32(w + 4);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi0x0123, vk0x0123);

      const float32x4_t vi1x0123 = vld1q_f32(i1); i1 += 4;
      const float32x4_t vk1x0123 = vld1q_f32(w + 12);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi1x0123, vk1x0123);

      const float32x4_t vi2x0123 = vld1q_f32(i2); i2 += 4;
      const float32x4_t vk2x0123 = vld1q_f32(w + 20);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi2x0123, vk2x0123);

      const float32x4_t vi3x0123 = vld1q_f32(i3); i3 += 4;
      const float32x4_t vk3x0123 = vld1q_f32(w + 28);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi3x0123, vk3x0123);

      const float32x4_t vi4x0123 = vld1q_f32(i4); i4 += 4;
      const float32x4_t vk4x0123 = vld1q_f32(w + 36);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi4x0123, vk4x0123);

      const float32x4_t vi5x0123 = vld1q_f32(i5); i5 += 4;
      const float32x4_t vk5x0123 = vld1q_f32(w + 44);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi5x0123, vk5x0123);

      const float32x4_t vi6x0123 = vld1q_f32(i6); i6 += 4;
      const float32x4_t vk6x0123 = vld1q_f32(w + 52);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi6x0123, vk6x0123);

      const float32x4_t vi7x0123 = vld1q_f32(i7); i7 += 4;
      const float32x4_t vk7x0123 = vld1q_f32(w + 60);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi7x0123, vk7x0123);

      const float32x4_t vi8x0123 = vld1q_f32(i8); i8 += 4;
      const float32x4_t vk8x0123 = vld1q_f32(w + 68);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi8x0123, vk8x0123);


      float32x4_t vacc0123 = vmaxq_f32(vacc0123p0, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);

      vst1q_f32(output, vacc0123); output += 4;
    }
    if XNN_UNLIKELY(c != 0) {
      float32x4_t vacc0123p0 = vld1q_f32(w);


      const float32x4_t vi0x0123 = vld1q_f32(i0);
      const float32x4_t vk0x0123 = vld1q_f32(w + 8);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi0x0123, vk0x0123);

      const float32x4_t vi1x0123 = vld1q_f32(i1);
      const float32x4_t vk1x0123 = vld1q_f32(w + 16);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi1x0123, vk1x0123);

      const float32x4_t vi2x0123 = vld1q_f32(i2);
      const float32x4_t vk2x0123 = vld1q_f32(w + 24);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi2x0123, vk2x0123);

      const float32x4_t vi3x0123 = vld1q_f32(i3);
      const float32x4_t vk3x0123 = vld1q_f32(w + 32);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi3x0123, vk3x0123);

      const float32x4_t vi4x0123 = vld1q_f32(i4);
      const float32x4_t vk4x0123 = vld1q_f32(w + 40);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi4x0123, vk4x0123);

      const float32x4_t vi5x0123 = vld1q_f32(i5);
      const float32x4_t vk5x0123 = vld1q_f32(w + 48);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi5x0123, vk5x0123);

      const float32x4_t vi6x0123 = vld1q_f32(i6);
      const float32x4_t vk6x0123 = vld1q_f32(w + 56);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi6x0123, vk6x0123);

      const float32x4_t vi7x0123 = vld1q_f32(i7);
      const float32x4_t vk7x0123 = vld1q_f32(w + 64);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi7x0123, vk7x0123);

      const float32x4_t vi8x0123 = vld1q_f32(i8);
      const float32x4_t vk8x0123 = vld1q_f32(w + 72);
      vacc0123p0 = vfmaq_f32(vacc0123p0, vi8x0123, vk8x0123);


      float32x4_t vacc0123 = vmaxq_f32(vacc0123p0, vmin);
      vacc0123 = vminq_f32(vacc0123, vmax);

      float32x2_t vacc01 = vget_low_f32(vacc0123);
      if (c & 2) {
        vst1_f32(output, vacc01); output += 2;
        vacc01 = vget_high_f32(vacc0123);
      }
      if (c & 1) {
        vst1_lane_f32(output, vacc01, 0); output += 1;
      }
    }

    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
