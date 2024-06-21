let bgColor;
let video1, video2, video3, video4, video5;
let videoGraphics;
let isVideo1Visible = false;
let emojis = [];
let slider1, slider2;
let button;
let textInput;
let displayText = '';

function setup() {
  createCanvas(displayWidth, displayHeight);
  bgColor = color(random(255), random(255), random(255));
  background(bgColor);

  // Create video players
  video1 = new VideoPlayer('videos/1.mp4', 10, 100, 320, 240);
  video1.play();
  video1.video.volume(0);

  video1.video.mouseOver(showVideo1);
  video1.video.mouseOut(hideVideo1);

  video2 = new VideoPlayer('videos/2.mp4', 100, 350, 320, 240);
  video2.play(); 

  video3 = new VideoPlayer('videos/3.mp4', 300, 110, 320, 240);
  video3.play();

  video4 = new VideoPlayer('videos/gifmp4.mp4', 600, 300, 320, 240);
  video4.play();

  video5 = new VideoPlayer('videos/the-internet.mp4', 900, 200, 320, 240);
  video5.play();

  for(var j = 0; j < 10; j++){
    for (let i = 0; i < 7; i++) {
      let emoji = createEmoji(random(width), random(height), 50, 'emojis/' + (i + 1) + '.jpg');
      emojis.push(emoji);
    }
  }

  slider1 = createSlider(0, 100, 50);
  slider1.position(400, 10); 

  slider2 = createSlider(0, 100, 50);
  slider2.position(400, 40);

  slider1.changed(handleSlider1Change);
  slider2.changed(handleSlider2Change);

  button = createButton('Click me');
  button.position(600, 30);
  button.mousePressed(handleButtonPress);

  textInput = createInput('Type something');
  textInput.position(700, 30);
  textInput.input(handleTextInput);
}

function draw() {
  background(bgColor);

  fill(0);
  textSize(32);
  text(displayText, 700, 30);

  for (let emoji of emojis) {
    emoji.move();
    emoji.display();
  }

  video2.show();
  video3.show();
  video4.show();
  video5.show();
}

class VideoPlayer {
  constructor(videoFile, x, y, w, h) {
    this.video = createVideo([videoFile]);
    this.video.size(w, h);
    this.video.position(x, y);
  }

  play() {
    this.video.loop();
  }

  hide() {
    this.video.hide();
  }

  pause() { 
    this.video.pause();
  }
  
  show() {
    this.video.show();
  }
}

class Emoji {
  constructor(x, y, size, path) {
    this.x = x;
    this.y = y;
    this.size = size;
    this.xSpeed = random(-2, 2);
    this.ySpeed = random(-2, 2);
    this.emoji = createImg(path);
    this.emoji.size(this.size, this.size);
    this.emoji.position(this.x, this.y);
  }

  move() {
    this.x += this.xSpeed;
    this.y += this.ySpeed;

    // Bounce off walls
    if (this.x < 0 || this.x > width) {
      this.xSpeed *= -1;
    }
    if (this.y < 0 || this.y > height) {
      this.ySpeed *= -1;
    }
  }

  display() {
    this.emoji.position(this.x, this.y);
  }
}

function createEmoji(x, y, size, path) {
  return new Emoji(x, y, size, path);
}

/* Change size video1 */
function handleSlider1Change() {
  let slider1Value = slider1.value();

  video1.video.size(slider1Value*10);
}

/* Change background color */
function handleSlider2Change() {
  let slider2Value = slider2.value();

  bgColor = color(slider2Value*10, slider2Value*5, slider2Value*2);
}

/* Change emoji */
function handleButtonPress() {
  for (let emoji of emojis) {
    emoji.emoji.attribute('src', 'emojis/' + floor(random(1, 7)) + '.jpg');
  }
}

/* Print text */
function handleTextInput() {
  displayText = textInput.value();
}

/* Show video1 */
function showVideo1() {
    video1.play();
}

/* Hide video1 */
function hideVideo1() {
    video1.pause();
}