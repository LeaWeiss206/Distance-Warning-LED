const pkg = require('@wokwi/elements');
const board = pkg.board;

// הגדרת החיישן האולטרסוני
const ultrasonic = board.getComponent('ultrasonic1');

function setDistance(distance) {
  console.log(`Setting distance to: ${distance}`);
  ultrasonic.setAttribute('distance', distance);
}

// התחברות לרשת ה-WiFi והבאת המרחקים מהשרת
async function fetchDistances() {
  console.log('Fetching distances from server...');
  const response = await fetch('https://api.jsonbin.io/v3/b/66a0d737acd3cb34a86a9513/latest');
  const data = await response.json();
  console.log('Distances fetched:', data.record.distances);
  return data.record.distances;
}

async function updateSensorDistance() {
  const distances = await fetchDistances();
  let currentIndex = 0;

  setInterval(() => {
    setDistance(distances[currentIndex]);
    currentIndex = (currentIndex + 1) % distances.length;
  }, 1000); // עדכון כל שנייה
}

// קריאה לפונקציה כדי לעדכן את המרחק של החיישן
updateSensorDistance();
