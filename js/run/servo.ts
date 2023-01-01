import { Board, Servo } from 'johnny-five';
const board = new Board();

board.on('ready', () => {
  const servo = new Servo(10);
  board.repl.inject({
    servo
  });
  let end = 180;
  let start = 0;

  const intId = setInterval(() => {
    servo.to(start, 250);
    servo.to(end, 250);
    start += 10;
    end -= 10;
    console.log(end, ': end');
    console.log(start, ': start');
    if(start >= end -10){
      clearInterval(intId);
    }
  }, 5000);
});

