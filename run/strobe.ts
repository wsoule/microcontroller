import { Board, Led } from 'johnny-five';

const board = new Board();

board.on('ready', () => {
  const light = new Led(13);

  console.log(light.pin);
  light.blink(500);
  // board.repl.inject({
  //   on: () => {
  //     light.on();
  //   },
  //   off: () => {
  //     light.off();
  //   }
  // });


});

