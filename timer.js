this.onmessage = function (e) {
  var centiseconds = e.data.centiseconds;
  var seconds = e.data.seconds;
  var minutes = e.data.minutes;
  setInterval(function () {
    centiseconds = centiseconds + 1;
    if (centiseconds === 100) {
      centiseconds = 0;
      seconds = seconds + 1;
    }
    if (seconds === 60) {
      seconds = 0;
      minutes = minutes + 1;
    }
    this.postMessage({
      centiseconds: centiseconds,
      seconds: seconds,
      minutes: minutes,
    });
  }, 10);
};