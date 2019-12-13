
"use strict";

let recognizerService = require('./recognizerService.js')
let SoundLocalisationService = require('./SoundLocalisationService.js')
let ASRService = require('./ASRService.js')

module.exports = {
  recognizerService: recognizerService,
  SoundLocalisationService: SoundLocalisationService,
  ASRService: ASRService,
};
