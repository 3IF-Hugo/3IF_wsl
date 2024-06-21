let bgColor;
let ballColor;
let balls = [];

function setup() {
  createCanvas(displayWidth, displayHeight);
  bgColor = color(random(255), random(255), random(255));

  for (let i = 0; i < 100; i++) {
    balls[i] = new Bubble(random(width), random(height), 4);
  }
}

function draw() {
  background(bgColor);

  for (let i = 0; i < balls.length; i++) {
    balls[i].show();
    balls[i].move();
    balls[i].rebound();
  }
}

class Bubble {
  constructor(_x, _y, _s) {
    this.x = _x;
    this.y = _y;
    // this.ballColor = color(random(255), random(255), random(255));
    this.ballColor = color(255);
    this.xSpeed = _s;
    this.ySpeed = _s;
  }

  move() {
    this.x += this.xSpeed;
    this.y += this.ySpeed;
  }

  rebound() {
    if (this.x > width - 25 || this.x < 25) {
      this.xSpeed *= -1;
      // this.ballColor = color(random(255), random(255), random(255));
    }
    
    if (this.y > height - 25 || this.y < 25) {
      this.ySpeed *= -1;
      // this.ballColor = color(random(255), random(255), random(255));
    }
  }

  show() {
    noStroke();
    fill(this.ballColor);
    ellipse(this.x, this.y, 50, 50);
  }

  getX() {
    return this.x;
  }
}
