import { Template } from 'meteor/templating';

import { Sensors } from '../api/sensors.js';

import './body.html';

Template.body.helpers({
	sensors: [
		{text : 'Sensor 1'},
		{text : 'Sensor 2'},
		{text : 'Sensor 3'},
	],
	sensors(){
		return Sensors.find({});
	},
});
