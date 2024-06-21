let bgColor;
let ballColor;

let bubble1;


function setup() {
  c = createCanvas(displayWidth, displayHeight);
  bgColor = color(random(255), random(255), random(255));
  bubble1 = new Bubble(25,25, 2);
  bubble2 = new Bubble(500,250, 4);
  bubble3 = new Bubble(250,500, 5);
}

function draw() {
  background(bgColor);
  
  bubble1.show();
  bubble1.move();
  bubble1.rebound();
  
  bubble2.show();
  bubble2.move();
  bubble2.rebound();
  
  bubble3.show();
  bubble3.move();
  bubble3.rebound();

}

class Bubble {
  constructor(_x, _y, _s) {
    this.x = _x;
    this.y = _y;
    this.ballColor = color(random(255), random(255), random(255));
    this.speed = _s;
  }

  move() {
    this.x += this.speed;
  }
  
  rebound(){
    if(this.x > width - 25 || this.x < 25){
      this.speed *= -1;
      console.log(random(0,100));
      bgColor = color(random(255), random(255), random(255));
      this.ballColor = color(random(255), random(255), random(255));
    }
  }

  show() {
    noStroke();
    fill(this.ballColor);
    ellipse(this.x, this.y, 50, 50);
  }
  
  getX(){
   return this.x; 
  }
}
