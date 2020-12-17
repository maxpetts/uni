var fft;
var song;
var w;

function toggleSong() {
  if (song.isPlaying()) {
    song.pause();
  } else {
    song.play();
  }
}

function preload() {
  song = loadSound('10cc - Dreadlock Holiday.mp3');
}

function setup() {
  createCanvas(400, 400);
  btn = createButton('toggle song');
  btn.mousePressed(toggleSong);
  song.play();
  fft = new p5.FFT(0.7, 60);
  w = width / 64;
}

function draw() {
  background(50, 150, 50);

  let spectrum = fft.analyze();
  stroke(255);

  let division = floor(spectrum.length / 3);

  

  for (let i = 0; i < spectrum.length; i++) {
    let amp = spectrum[i];
    let y = map(amp, 0, 256, height, 0);

    rect(i * w, y, w - 2, height - y)

  }

}