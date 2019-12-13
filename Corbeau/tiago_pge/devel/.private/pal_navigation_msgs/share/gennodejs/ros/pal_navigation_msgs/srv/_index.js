
"use strict";

let ChangeBuilding = require('./ChangeBuilding.js')
let SetPOI = require('./SetPOI.js')
let RenameMap = require('./RenameMap.js')
let GetNodes = require('./GetNodes.js')
let GetMapConfiguration = require('./GetMapConfiguration.js')
let ListMaps = require('./ListMaps.js')
let Acknowledgment = require('./Acknowledgment.js')
let SetMapConfiguration = require('./SetMapConfiguration.js')
let SetSubMapFloor = require('./SetSubMapFloor.js')
let SafetyZone = require('./SafetyZone.js')
let SaveMap = require('./SaveMap.js')
let GetPOI = require('./GetPOI.js')
let GetSubMap = require('./GetSubMap.js')
let VisualLocRecognize = require('./VisualLocRecognize.js')
let DisableEmergency = require('./DisableEmergency.js')
let FinalApproachPose = require('./FinalApproachPose.js')

module.exports = {
  ChangeBuilding: ChangeBuilding,
  SetPOI: SetPOI,
  RenameMap: RenameMap,
  GetNodes: GetNodes,
  GetMapConfiguration: GetMapConfiguration,
  ListMaps: ListMaps,
  Acknowledgment: Acknowledgment,
  SetMapConfiguration: SetMapConfiguration,
  SetSubMapFloor: SetSubMapFloor,
  SafetyZone: SafetyZone,
  SaveMap: SaveMap,
  GetPOI: GetPOI,
  GetSubMap: GetSubMap,
  VisualLocRecognize: VisualLocRecognize,
  DisableEmergency: DisableEmergency,
  FinalApproachPose: FinalApproachPose,
};
