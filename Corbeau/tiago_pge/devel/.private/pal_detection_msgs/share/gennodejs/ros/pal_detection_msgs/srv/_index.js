
"use strict";

let AddTexturedObject = require('./AddTexturedObject.js')
let Recognizer = require('./Recognizer.js')
let StopEnrollment = require('./StopEnrollment.js')
let StartEnrollment = require('./StartEnrollment.js')
let SetDatabase = require('./SetDatabase.js')
let SelectTexturedObject = require('./SelectTexturedObject.js')
let ChangeObjectRecognizerModel = require('./ChangeObjectRecognizerModel.js')

module.exports = {
  AddTexturedObject: AddTexturedObject,
  Recognizer: Recognizer,
  StopEnrollment: StopEnrollment,
  StartEnrollment: StartEnrollment,
  SetDatabase: SetDatabase,
  SelectTexturedObject: SelectTexturedObject,
  ChangeObjectRecognizerModel: ChangeObjectRecognizerModel,
};
