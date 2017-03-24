var SerialPort = require('serialport');
var thinkgear = require('node-thinkgear-sockets');

var client = thinkgear.createClient();

var readings = {}
var threshold = false; 

var serialReady = false; 

var maxSpeed = 255; 
var minSpeed = 140; 

var port = new SerialPort('COM4', function (err) {
  if (err) {
    return console.log('Error: ', err.message);
  }
  serialReady = true; 
  
}); 
client.on('data',function(data){
  console.log((new Date).toISOString() + ': ' + JSON.stringify(data));
  //readings = JSON.stringify(data); 
  readings = data; 

  if(serialReady){ 

    /*
    console.log("readings = "+readings); 
    console.log("reading[eSense] = "+readings["eSense"]); 
    console.log("readings keys = "+Object.keys(readings)); 
    */
    if(readings["eSense"]){ 
      console.log(readings['eSense']['attention']); 
      attention = readings['eSense']['attention']; 
      /*
      if(attention < 50){ 
        threshold = true; 
      } 
      else{ 
        threshold = false; 
      } 
      */
    } 
    if (attention > 25) { 
      // m = move the car 
      speed = Math.floor(minSpeed + ((attention/100) * (maxSpeed - minSpeed))); 
      port.write(speed.toString()+'\n', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message);
        }
        console.log('move the car at speed = '+speed);
      });
    } 
    else{ 
      port.write('0\n', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message);
        }
        console.log('stop the car');
      });

    }

  } 
});

client.connect();

