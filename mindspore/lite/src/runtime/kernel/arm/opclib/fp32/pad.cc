/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "src/runtime/kernel/arm/opclib/fp32/pad.h"
#include "src/runtime/kernel/arm/opclib/common_func.h"

void Pad(const float *input_data, float *output_data, const int *input_shape, const int *output_shape,
         const int *paddings, const int tid, const int thread_num) {
  int in[4], out[4];
  for (in[0] = 0; in[0] < input_shape[0]; in[0]++) {
    out[0] = in[0] + paddings[0];
    for (in[1] = tid; in[1] < input_shape[1]; in[1] += thread_num) {
      out[1] = in[1] + paddings[2];
      for (in[2] = 0; in[2] < input_shape[2]; in[2]++) {
        out[2] = in[2] + paddings[4];
        float *dst = output_data + offset(output_shape, out[0], out[1], out[2], paddings[6]);
        const float *src = input_data + offset(input_shape, in[0], in[1], in[2], 0);
        memcpy(dst, src, input_shape[3] * sizeof(float));
      }
    }
  }
}
