let corsAnywhereURL = 'https://cors-anywhere.herokuapp.com/';
let corsautre = 'https://api.allorigins.win/get?url=';
let corsautre2 = 'https://proxy.cors.sh/';
// let startingPage = encodeURIComponent('https://en.wikipedia.org/wiki/Peiponen');
let startingPage = 'https://en.wikipedia.org/wiki/University_of_Limerick';
let currentPageURL = corsautre2 + startingPage;
let images = [];
let links = [];

function setup() {
  createCanvas(windowWidth, windowHeight);
  loadPageContent(currentPageURL);
}

function draw() {
  background(255);
  displayContent();
}

function loadPageContent(url) {
  httpGet(url, 'text', function(response) {
    if (response) {
      let pageHTML = response;
      console.log("pageHTML", pageHTML);
    
      // Extracte links:
      let linkRegex = /<a\s+(?:[^>]*?\s+)?href=['"]([^'"]+)['"][^>]*>(.*?)<\/a>/g;
      let linkMatches = pageHTML.match(linkRegex);
      if (linkMatches) {
        links = linkMatches.map(match => {
          let parts = match.match(/href=['"]([^'"]+)['"][^>]*>(.*?)<\/a>/);
          let url = corsautre2 + "https://en.wikipedia.org" + parts[1];
          console.log("url", parts[1]);
          let linkText = parts[2].replace(/<[^>]*>/g, '');
          return { url: url, text: linkText  };
        });

        links = links.filter(link => link.url.startsWith(corsautre2 + "https://en.wikipedia.org/wiki/"));
        console.log("links", links);
        shuffleArray(links);
      }

      linkPositions = [];
      for (let i = 0; i < links.length; i++) {
        let x = random(width-200);
        let y = random(10, height-10);
        linkPositions.push({ x, y });
      }
    } else {
      console.error('Failed to fetch content from', url);
    }
  }, function(error) {
    console.error('Error occurred while fetching', url, error);
  });
}


function displayContent() {
  textSize(16);
  textAlign(LEFT);

  fill(0, 0, 255);
  let maxLinks = min(links.length, 15);
  for (let i = 0; i < maxLinks; i++) {
    let linkText = links[i].text;
    let x = linkPositions[i].x;
    let y = linkPositions[i].y;
    text(linkText, x, y);
    // console.log("linkText", links[i].url);
  }
}

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
}
