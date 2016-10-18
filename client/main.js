import { Template } from 'meteor/templating';
import { ReactiveVar } from 'meteor/reactive-var';

import './main.html';

Template.sensorlist.onCreated(function senseOnCreated() {
  // counter starts at 0
  this.sensorval1 = new ReactiveVar(11);
});

Template.sensorlist.helpers({
  	sensorval_arr: ["11","22","33","44","55"]
  
});
