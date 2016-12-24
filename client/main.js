import { Template } from 'meteor/templating';
import { ReactiveVar } from 'meteor/reactive-var';
import { Sensors } from '../imports/api/sensors.js';
import './main.css';
import './main.html';

Template.sensorlist.onCreated(function senseOnCreated() {
  // counter starts at 0
  this.sensorval1 = new ReactiveVar(11);
});

Template.sensorlist.helpers({
  	//Commented to now use MongdoDb
  	/*
  	sensorvals: [
  		{name:"Sensor 1", val: "1"},
  		{name:"Sensor 2", val: "1"},
  		]
  	*/
  	sensorvals(){
  		return Sensors.find({});
  	},
});
