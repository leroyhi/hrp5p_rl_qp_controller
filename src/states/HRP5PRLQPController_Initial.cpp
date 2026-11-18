#include "HRP5PRLQPController_Initial.h"

#include <HRP5PRLQPController.h>

void HRP5PRLQPController_Initial::configure(const mc_rtc::Configuration &) {}

void HRP5PRLQPController_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<HRP5PRLQPController &>(ctl_);
  ctl.rlStateRunner.start(ctl, "RL_State");
}

bool HRP5PRLQPController_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<HRP5PRLQPController &>(ctl_);
  ctl.rlStateRunner.run(ctl);
  ctl.torqueJointTask->setPosTarget(ctl.rlRuntime().q_rl());
  return false;
}

void HRP5PRLQPController_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<HRP5PRLQPController &>(ctl_);
}

EXPORT_SINGLE_STATE("HRP5PRLQPController_Initial", HRP5PRLQPController_Initial)
