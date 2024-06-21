let imgWidth;
let imgHeight;
let numImagesHeight;
let numImagesWidth;
let xOffset = 0;
let lastUpdateTime = 0;

let image1;
let image2;

let columns1 = [];
let columns2 = [];

class ImageObject {
  constructor(image, x, y, w, h) {
    this.image = image;
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
  }

  display() {
    image(this.image, this.x, this.y, this.w, this.h);
  }

  shiftX(amount) {
    this.x += amount;
    if (this.x >= width) {
      this.x -= width;
    }
  }
}

function preload() {
  image1 = loadImage('videos/1.jpg');
  image2 = loadImage('videos/2.jpg');
}

function setup() {
  createCanvas(displayWidth, displayHeight);

  imgWidth = width / 12;
  imgHeight = height / 12;
  numImagesHeight = height / imgHeight;
  numImagesWidth = width / imgWidth;

  for (let j = 0; j < numImagesWidth; j++) {
    columns2[j] = [];
    columns1[j] = [];
    for (let i = 0; i < numImagesHeight; i++) {
      let x = j * imgWidth + xOffset;
      let y = i * imgHeight;

      if (x >= width) {
        x -= width;
      }

      if (j % 2 == 0) {
        columns1[j][i] = new ImageObject(image1, x, y, imgWidth, imgHeight);
      } else {
        columns2[j][i] = new ImageObject(image2, x, y, imgWidth, imgHeight);
      }
    }
  }

  let toggleButton = createButton('Stop freezing my browser!');
  toggleButton.size(200, 30);
  toggleButton.position(width / 2 - 100, height / 4 + 50);
  toggleButton.mousePressed(stopFreezingMyBrowser);

  let toggleButton2 = createButton('Let\'s start again!');
  toggleButton2.size(200, 30);
  toggleButton2.position(width / 2 - 100, height / 4 + 90);
  toggleButton2.mousePressed(freezeAgain);
}

function draw() {
  setInterval(shiftColumn, 2000);

  background(255);

  for (let j = 0; j < numImagesWidth; j++) {
    for (let i = 0; i < numImagesHeight; i++) {
      if (j % 2 == 0) {
        columns1[j][i].display();
      } else {
        columns2[j][i].display();
      }
    }
  }

  fill(255);
  textSize(32);
  textAlign(CENTER, CENTER);
  text('How do you like it?', width / 2, height / 4);
}

function stopFreezingMyBrowser() {
  noLoop();
}

function freezeAgain() { 
  loop();
}

function shiftColumn() {
  xOffset = imgWidth;
  for (let j = 0; j < numImagesWidth; j++) {
    for (let i = 0; i < numImagesHeight; i++) {
      if (j % 2 == 0) {
        columns1[j][i].shiftX(imgWidth);
      } else {
        columns2[j][i].shiftX(imgWidth);
      }
    }
  }
}
