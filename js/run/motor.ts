import { Board, Motor } from 'johnny-five';
const board = new Board();

board.on('ready', () => {
  const motor = new Motor([5]);
  board.repl.inject({
    motor
  });

  motor.start();
  board.wait(2000, motor.stop);

});
