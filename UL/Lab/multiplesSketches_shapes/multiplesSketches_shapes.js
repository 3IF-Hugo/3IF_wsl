// Sketch 1
var sketch1 = function(p1) {
  let x1, y1;
  let triangleSize = 200;

  p1.setup = function() {
    p1.createCanvas(p1.windowWidth / 3, p1.windowHeight);
    x1 = p1.width / 2;
    y1 = p1.height / 2;
  }

  p1.draw = function() {
    p1.background(0);
    p1.translate(x1, y1);
    p1.fill(255, 0, 0);

    // Calculate triangle peak positions relative to canvas size
    let xPeak1 = -triangleSize / 2;
    let yPeak1 = triangleSize / 4;
    let xPeak2 = 0;
    let yPeak2 = -triangleSize / 4;
    let xPeak3 = triangleSize / 2;
    let yPeak3 = triangleSize / 4;

    p1.triangle(xPeak1, yPeak1, xPeak2, yPeak2, xPeak3, yPeak3);
  }
}


// Sketch 2
var sketch2 = function(p2) {
  let angle2 = 0;

  p2.setup = function() {
    p2.createCanvas(p2.windowWidth/3, p2.windowHeight);
  }

  p2.draw = function() {
    p2.background(0);
    p2.translate(p2.width / 2, p2.height / 2);
    p2.rotate(angle2);
    p2.fill(0, 255, 0);
    p2.rect(-50, -50, 100, 100);
    angle2 -= 0.03;
  }
}

// Sketch 3
var sketch3 = function(p3) {
  let x3 = 200;
  let y3 = 200;
  let xSpeed3 = 2;
  let ySpeed3 = 1;

  p3.setup = function() {
    let widthP3 = p3.windowWidth/3 - 20;
    p3.createCanvas(widthP3, p3.windowHeight);
  }

  p3.draw = function() {
    p3.background(0);
    p3.fill(0, 0, 255);
    p3.ellipse(x3, y3, 50, 50);
    x3 += xSpeed3;
    y3 += ySpeed3;

    if (x3 > p3.width - 25 || x3 < 25) {
      xSpeed3 *= -1;
    }
    if (y3 > p3.height - 25 || y3 < 25) {
      ySpeed3 *= -1;
    }
  }
}

// Create instances of each sketch
new p5(sketch1);
new p5(sketch2);
new p5(sketch3);
