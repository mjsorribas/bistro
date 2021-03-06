/*
 *  Copyright (c) 2015-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <unordered_map>

#include <folly/dynamic.h>

#include "bistro/bistro/if/gen-cpp2/common_types.h"

namespace facebook { namespace bistro {

class JobBackoffSettings {

public:
  JobBackoffSettings();
  explicit JobBackoffSettings(const folly::dynamic& d);

  cpp2::BackoffDuration getNext(const cpp2::BackoffDuration& cur) const;

  folly::dynamic toDynamic() const;

  bool operator==(const JobBackoffSettings&) const;
  bool operator!=(const JobBackoffSettings&) const;

private:
  std::vector<int> values_;
  bool repeat_;

};

}}
