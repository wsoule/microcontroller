import { Board, Proximity } from 'johnny-five';
const board = new Board();

board.on('ready', () => {
  const proximity = new Proximity({
    controller: 'HCSR04',
    pin: 7
  });
  proximity.on('data', (data) => {
    const inch = data.in;
    const cm = data.cm;
    console.log(`Proximity: ${cm} cm : ${inch} in`);
    console.log('----------------');
  });
});
