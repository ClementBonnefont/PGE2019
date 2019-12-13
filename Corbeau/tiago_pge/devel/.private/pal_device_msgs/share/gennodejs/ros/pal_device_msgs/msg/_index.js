
"use strict";

let LedRainbowParams = require('./LedRainbowParams.js');
let LedPreProgrammedParams = require('./LedPreProgrammedParams.js');
let LedGroup = require('./LedGroup.js');
let LedEffectViaTopicParams = require('./LedEffectViaTopicParams.js');
let LedFlowParams = require('./LedFlowParams.js');
let LedEffectParams = require('./LedEffectParams.js');
let BatteryState = require('./BatteryState.js');
let Bumper = require('./Bumper.js');
let LedFixedColorParams = require('./LedFixedColorParams.js');
let LedBlinkParams = require('./LedBlinkParams.js');
let LedFadeParams = require('./LedFadeParams.js');
let LedDataArrayParams = require('./LedDataArrayParams.js');
let LedProgressParams = require('./LedProgressParams.js');
let DoTimedLedEffectGoal = require('./DoTimedLedEffectGoal.js');
let DoTimedLedEffectAction = require('./DoTimedLedEffectAction.js');
let DoTimedLedEffectActionGoal = require('./DoTimedLedEffectActionGoal.js');
let DoTimedLedEffectResult = require('./DoTimedLedEffectResult.js');
let DoTimedLedEffectActionResult = require('./DoTimedLedEffectActionResult.js');
let DoTimedLedEffectFeedback = require('./DoTimedLedEffectFeedback.js');
let DoTimedLedEffectActionFeedback = require('./DoTimedLedEffectActionFeedback.js');

module.exports = {
  LedRainbowParams: LedRainbowParams,
  LedPreProgrammedParams: LedPreProgrammedParams,
  LedGroup: LedGroup,
  LedEffectViaTopicParams: LedEffectViaTopicParams,
  LedFlowParams: LedFlowParams,
  LedEffectParams: LedEffectParams,
  BatteryState: BatteryState,
  Bumper: Bumper,
  LedFixedColorParams: LedFixedColorParams,
  LedBlinkParams: LedBlinkParams,
  LedFadeParams: LedFadeParams,
  LedDataArrayParams: LedDataArrayParams,
  LedProgressParams: LedProgressParams,
  DoTimedLedEffectGoal: DoTimedLedEffectGoal,
  DoTimedLedEffectAction: DoTimedLedEffectAction,
  DoTimedLedEffectActionGoal: DoTimedLedEffectActionGoal,
  DoTimedLedEffectResult: DoTimedLedEffectResult,
  DoTimedLedEffectActionResult: DoTimedLedEffectActionResult,
  DoTimedLedEffectFeedback: DoTimedLedEffectFeedback,
  DoTimedLedEffectActionFeedback: DoTimedLedEffectActionFeedback,
};
