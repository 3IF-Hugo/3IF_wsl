let images = [];
let numImages = 5;
let imageWidth = 200;
let imageHeight = 200;
let imageDisplays = [];

class ImageDisplay {
  constructor(image, x, y) {
    this.image = image;
    this.x = x;
    this.y = y;
  }

  display() {
    image(this.image, this.x, this.y, imageWidth, imageHeight);
  }

  updatePosition() {
    this.x = random(0, displayWidth - imageWidth);
    this.y = random(0, displayHeight - imageHeight);
  }
}

function preload() {
  images.push(loadImage('landscape.jpg'));
}

function setup() {
  createCanvas(displayWidth, displayHeight);
  for (let i = 0; i < numImages; i++) {
    let x = random(0, displayWidth - imageWidth);
    let y = random(0, displayHeight - imageHeight);
    let imageDisplay = new ImageDisplay(images[0], x, y);
    imageDisplays.push(imageDisplay);
    imageDisplay.display();
  }
}

function draw() {
}

function keyPressed() {
  if (key === 'n') {
    for (let i = 0; i < imageDisplays.length; i++) {
      imageDisplays[i].updatePosition();
      imageDisplays[i].display();
    }
  }
}
