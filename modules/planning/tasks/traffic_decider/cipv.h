/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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
 *****************************************************************************/

/**
 * @file
 **/

#ifndef MODULES_PLANNING_TASKS_TRAFFIC_DECIDER_CIPV_H_
#define MODULES_PLANNING_TASKS_TRAFFIC_DECIDER_CIPV_H_

#include "modules/perception/proto/perception_obstacle.pb.h"

#include "modules/planning/common/frame.h"
#include "modules/planning/common/reference_line_info.h"
#include "modules/planning/tasks/traffic_decider/traffic_rule.h"

namespace apollo {
namespace planning {

class CIPV : public TrafficRule {
 public:
  explicit CIPV(const RuleConfig& config);
  ~CIPV() = default;

  bool ApplyRule(Frame* frame, ReferenceLineInfo* reference_line_info);

 private:
  bool CreateFollowDecision(const PathObstacle& path_obstacle,
                            const ReferenceLineInfo* reference_line_info,
                            ObjectDecisionType* const follow_decision);
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_TASKS_TRAFFIC_DECIDER_CIPV_H_