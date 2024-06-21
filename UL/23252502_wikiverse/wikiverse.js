/*
  In the case of CORS error, you can use the other proxy (https://cors-anywhere.herokuapp.com/)
  You just have to activate it by uncommenting the lines 7 and 8 and commenting the lines 11 and 12
  AND ask for the demo server to be activated on the website https://cors-anywhere.herokuapp.com/corsdemo
*/

// With cors-anywhere.herokuapp.com
  // let corsProxy = 'https://cors-anywhere.herokuapp.com/';
  // let headers = {};

// With proxy.cors.sh
  let corsProxy = 'https://proxy.cors.sh/';
  let headers = {
    'x-cors-api-key': 'temp_4ef84689a8192f0e7ae580b9407da9b5'
  };


let startingPage = 'https://en.wikipedia.org/wiki/France';
let currentPageURL = corsProxy + startingPage;
let links = [];
let bgColors = [];
let transitionAlpha = 0;
let nbLinks = 15;
let oneError = false;

let gifSurfing;
let corsErrorMessage;
let corsErrorMessage1;
let corsErrorMessage2;

function setup() {
  createCanvas(displayWidth, displayHeight);
  loadPageContent(currentPageURL);
  bgColors.push(color(random(255), random(255), random(255)));

  gifSurfing = new VideoPlayer('surfingInternet.mp4', 450, 200, 250, 250);
  gifSurfing.play();
  gifSurfing.hide();
  corsErrorMessage = new FloatingText("End of surf session!", random(100), random(80), 16, random(-2, 2), random(-2, 2));
  corsErrorMessage1 = new FloatingText("Proxy says no more!", random(400, 600), random(280, 400), 16, random(-2, 2), random(-2, 2));
  corsErrorMessage2 = new FloatingText("And whitout proxy, CORS says no!", random(600, 700), random(80), 16, random(-2, 2), random(-2, 2));
}

function draw() {
  background(bgColors[bgColors.length - 1]);
  
  if (transitionAlpha > 0) {
    fill(0, 0, 0, transitionAlpha);
    rect(0, 0, width, height);
    transitionAlpha -= 10;
  }
  
  displayContent();

  // If you want to test the error message, uncomment the line below and comment the line 53
    // oneError = true;

  if (oneError) {
    gifSurfing.show();

    bgColors.push(0); 
    corsErrorMessage.update();
    corsErrorMessage.display();
    corsErrorMessage.checkBounds();

    corsErrorMessage1.update();
    corsErrorMessage1.display();
    corsErrorMessage1.checkBounds();

    corsErrorMessage2.update();
    corsErrorMessage2.display();  
    corsErrorMessage2.checkBounds();
  }
}

function loadPageContent(url) {
  httpDo(
    url,
    {
      method: 'GET',
      headers: headers
    }, function(response) {
    if (response) {
      oneError = false;
      let pageHTML = response;
    
      // Extract links:
      let linkRegex = /<a\s+(?:[^>]*?\s+)?href=['"]([^'"]+)['"][^>]*>(.*?)<\/a>/g;
      let linkMatches = pageHTML.match(linkRegex);
      if (linkMatches) {
        links = linkMatches.map(match => {
          let parts = match.match(/href=['"]([^'"]+)['"][^>]*>(.*?)<\/a>/);
          let url = corsProxy + "https://en.wikipedia.org" + parts[1];
          let linkText = parts[2].replace(/<[^>]*>/g, '');
          let fontSize = random(12, 36); 
          let textColor = color(random(255), random(255), random(255)); 
          let bgColor = color(random(255), random(255), random(255)); 

          const { positionX, positionY } = generateRandomUniquePosition(links, linkText, fontSize);
          return new Link(url, linkText, positionX, positionY, fontSize, textColor, bgColor);
        });

        links = links.filter(link => {
          const url = link.url.toLowerCase();
          return (
            url.startsWith(corsProxy + "https://en.wikipedia.org/wiki/") &&
            !url.includes("wiki/help") &&
            !url.includes("wiki/special") &&
            !url.includes("wiki/wikipedia")
          );
        });
        
        shuffleArray(links);
        links = links.slice(0, nbLinks);
        console.log(links);
      }
    } else {
      console.error('Failed to fetch content from', url);
    }
  }, function(error) {
    console.error('Error occurred while fetching', url, error);
    oneError = true;
  });
}

function generateRandomUniquePosition(existingLinks, text, fontSize) {
  const maxAttempts = 100;
  let attempts = 0;
  
  while (attempts < maxAttempts) {
    const positionX = random(width - 200);
    const positionY = random(10, height - 10);
    
    const collision = existingLinks.some(link => {
      textSize(link.fontSize);
      const w = textWidth(link.text) + 10;
      const h = link.fontSize + 20;
      const x = link.positionX;
      const y = link.positionY - h;
      if ((positionX > x && positionX < x + w && positionY > y && positionY < y + h) || (x > positionX && x < positionX + textWidth(text) && y > positionY && y < positionY + fontSize)) {
        return true;
      }
    });
    
    if (!collision) {
      return { positionX, positionY };
    }
    
    attempts++;
  }

  return { positionX: random(width - 200), positionY: random(10, height - 10) };
}

function displayContent() {
  for (let i = 0; i < links.length; i++) {
    let link = links[i];
    textSize(link.fontSize);
    fill(link.bgColor);
    rect(link.positionX - 5, link.positionY - 10 - link.fontSize , textWidth(link.text) + 10, textAscent() + textDescent() + 20);
    fill(link.textColor);
    text(link.text, link.positionX, link.positionY);
  }
}

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
}

function mousePressed() {
  const linkPresent = [];

  for (let i = 0; i < links.length; i++) {
    let link = links[i];
    let x = link.positionX;
    let y = link.positionY;
    let w = textWidth(link.text);
    let h = textAscent() + textDescent();
    if (mouseX > x && mouseX < x + w && mouseY > y - h && mouseY < y) {
      linkPresent.push(link);
    }
  }

  if (linkPresent.length > 0) {
    const randomLink = links[Math.floor(random(links.length))];
    transitionAlpha = 255;
    
    setTimeout(() => {
      loadPageContent(randomLink.url);
      bgColors.push(color(random(255), random(255), random(255))); 
      if (bgColors.length > 3) {
        bgColors.shift(); 
      }
    }, 500); 
  }
}

class Link {
  constructor(url, text, positionX, positionY, fontSize, textColor, bgColor) {
    this.url = url;
    this.text = text;
    this.positionX = positionX;
    this.positionY = positionY;
    this.fontSize = fontSize;
    this.textColor = textColor;
    this.bgColor = bgColor;
  }
}

class FloatingText {
  constructor(text, x, y, fontSize, speedX, speedY) {
    this.text = text;
    this.x = x;
    this.y = y;
    this.fontSize = fontSize;
    this.speedX = speedX;
    this.speedY = speedY;
    this.trail = [];
  }

  update() {
    this.x += this.speedX;
    this.y += this.speedY;
    this.trail.push({ x: this.x, y: this.y });

    if (this.trail.length > 10) {
      this.trail.shift();
    }
  }

  display() {
    for (let i = 0; i < this.trail.length; i++) {
      let pos = this.trail[i];
      fill(255);
      rect(pos.x, pos.y, textWidth(text) + 100, this.fontSize + 20);
      fill(0);
      textSize(this.fontSize);
      textAlign(CENTER);
      text(this.text, pos.x + 10, pos.y + 10, textWidth(text) + 80, this.fontSize + 20);
    }
  }

  checkBounds() {
    if (this.x < 0 || this.x + textWidth(text) + 20 > width) {
      this.speedX *= -1; 
    }
    if (this.y < 0 || this.y > height - this.fontSize) {
      this.speedY *= -1; 
    }
  }
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

