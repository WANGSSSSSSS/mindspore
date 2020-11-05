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

#ifndef MINDSPORE_CCSRC_BACKEND_KERNEL_COMPILER_AKG_GPU_AKG_GPU_KERNEL_BUILD_H_
#define MINDSPORE_CCSRC_BACKEND_KERNEL_COMPILER_AKG_GPU_AKG_GPU_KERNEL_BUILD_H_
#include <string>
#include "backend/kernel_compiler/kernel.h"
#include "backend/kernel_compiler/akg/akg_kernel_json_generator.h"
#include "base/base.h"

namespace mindspore {
namespace kernel {
class AkgGpuKernelBuilder {
 public:
  AkgGpuKernelBuilder() = default;
  ~AkgGpuKernelBuilder() = default;

  KernelModPtr BuildByJson(const AnfNodePtr &anf_node);
  KernelModPtr FuseByJson(const AnfNodePtr &anf_node);

 private:
  KernelPackPtr OpBuild(const AkgKernelJsonGenerator &json_generator, const AnfNodePtr &anf_node);
};

KernelModPtr AkgGpuKernelBuild(const AnfNodePtr &anf_node);
}  // namespace kernel
}  // namespace mindspore

#endif  // MINDSPORE_CCSRC_BACKEND_KERNEL_COMPILER_AKG_GPU_AKG_GPU_KERNEL_BUILD_H_