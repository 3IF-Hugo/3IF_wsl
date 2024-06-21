let bgColor;
let slider1;
let slider2;
let video;

function setup() {
  createCanvas(displayWidth, displayHeight);
  bgColor = color(random(255), random(255), random(255));

  slider1 = createSlider(0, 255, 100);
  slider1.position(10, 100);
  slider1.style('color', 'red');

  slider2 = createSlider(0, 255, 100);
  slider2.position(10, 150);
  slider2.style('color', 'green');

  video = createVideo(['gifmp4.mp4']);
  video.size(320, 240);
  video.position(10, 300); 
  video.loop(); 
}

function draw() {
  let val = slider1.value();
  background(val);

  let val2 = slider2.value();
  ellipse(400, 100, val2, val2);
}

function mousePressed() {
  video.hide();
}

function mouseReleased() {
  video.show();
}