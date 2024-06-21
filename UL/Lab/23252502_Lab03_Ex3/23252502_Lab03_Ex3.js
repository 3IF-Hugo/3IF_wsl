let bgColor;
let video1, video2, video3, video4, video5;
let emojis = [];

function setup() {
  createCanvas(displayWidth, displayHeight);
  bgColor = color(random(255), random(255), random(255));
  background(bgColor);

  // Create video players
  video1 = new VideoPlayer('videos/1.mp4', 10, 100, 320, 240);
  video1.play();

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
}

function draw() {
  for (let emoji of emojis) {
    emoji.move();
    emoji.display();
  }

  video1.show();
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
