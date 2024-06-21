let numCanvases = 5;
let canvases = [];

function setup() {
  createCanvas(windowWidth, windowHeight);
  for (let i = 0; i < numCanvases; i++) {
    let x = random(width); 
    let y = random(height); 
    let w = random(100, 300);
    let h = random(100, 300);
    canvases.push(new FloatingCanvas(x, y, w, h));
  }
}

function draw() {
  background(220);

  for (let i = 0; i < canvases.length; i++) {
    canvases[i].display();
    canvases[i].float();
  }
}

class FloatingCanvas {
  constructor(x, y, w, h) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.speedX = random(-1, 1);
    this.speedY = random(-1, 1);
    this.canvas = createGraphics(this.w, this.h);
    this.canvas.background(random(255), random(255), random(255));
    this.canvas.fill(255);
  }

  display() {
    image(this.canvas, this.x, this.y);
  }

  float() {
    this.x += this.speedX;
    this.y += this.speedY;

    if (this.x > width) {
      this.x = -this.w;
    } else if (this.x < -this.w) {
      this.x = width;
    }

    if (this.y > height) {
      this.y = -this.h;
    } else if (this.y < -this.h) {
      this.y = height;
    }
  }
}

function windowResized() {
  resizeCanvas(windowWidth, windowHeight);
}
