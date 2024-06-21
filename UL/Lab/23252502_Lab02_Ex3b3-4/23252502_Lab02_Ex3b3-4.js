let bgColor;
let ballColor;
let balls = [];
let ballRadius = 25;

function setup() {
  createCanvas(displayWidth, displayHeight);
  bgColor = color(random(255), random(255), random(255));
  ballColor = color(random(255), random(255), random(255));

  for (let i = 0; i < 100; i++) {
    balls[i] = new Bubble(random(width), random(height), random(4, 8), ballRadius);
  }

  setInterval(changeColorsAndRadius, 2000);
}

function draw() {
  background(bgColor);

  for (let i = 0; i < balls.length; i++) {
    balls[i].show();
    balls[i].move();
    balls[i].rebound();
  }
}

function changeColorsAndRadius() {
  bgColor = color(random(255), random(255), random(255));
  ballColor = color(random(255), random(255), random(255));
  ballRadius += 5;
  for (let i = 0; i < balls.length; i++) {
    balls[i].updateRadius(ballRadius);
  }
}

class Bubble {
  constructor(_x, _y, _s, _r) {
    this.x = _x;
    this.y = _y;
    this.speed = _s;
    this.radius = _r;
  }

  move() {
    this.x += random(-this.speed, this.speed);
    this.y += random(-this.speed, this.speed);
  }

  rebound() {
    if (this.x < 0 || this.x > width) {
      this.speed *= -1;
    }
    if (this.y < 0 || this.y > height) {
      this.speed *= -1;
    }
  }

  show() {
    noStroke();
    fill(ballColor);
    ellipse(this.x, this.y, this.radius * 2, this.radius * 2);
  }

  updateRadius(newRadius) {
    this.radius = newRadius;
  }
}
