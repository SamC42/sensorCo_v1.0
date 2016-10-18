import { Template } from 'meteor/templating';
import { ReactiveVar } from 'meteor/reactive-var';

import './main.html';

Template.sensorlist.onCreated(function senseOnCreated() {
  // counter starts at 0
  this.sensorval1 = new ReactiveVar(11);
});

Template.sensorlist.helpers({
  	sensorval_arr: [
  		{name:"Sensor 1", val: "1"},
  		{name:"Sensor 2", val: "1"},
  		]
  	//Need to grab from MongoDB
  
});
