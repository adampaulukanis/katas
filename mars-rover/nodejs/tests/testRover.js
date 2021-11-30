/* jshint node: true, esversion: 6 */
const assert = require('assert');
const mocha = require('mocha');
const Rover = require('..');

const N = 0,
  S = 180,
  E = 90,
  W = 270;
const LEFT = -90;
const RIGHT = 90;

describe('Rover', function () {
  const marsRover = new Rover();
  it('has starting position (0, 0)', function () {
    assert(marsRover.pos.x === 0);
    assert(marsRover.pos.y === 0);
  });

  it('has a direction', function () {
    const directions = [N, S, E, W];
    assert(directions.includes(marsRover._direction));
  });

  it('can go forward', function () {
    // Test all 4 directions
    marsRover._direction = N;
    marsRover.forward();
    assert(marsRover.pos.x === 0);
    assert(marsRover.pos.y === -1);

    marsRover._direction = S;
    marsRover.forward();
    assert(marsRover.pos.x === 0);
    assert(marsRover.pos.y === 0);

    marsRover._direction = E;
    marsRover.forward();
    assert(marsRover.pos.x === 1);
    assert(marsRover.pos.y === 0);

    marsRover._direction = W;
    marsRover.forward();
    assert(marsRover.pos.x === 0);
    assert(marsRover.pos.y === 0);
  });

  it('can go backward', function () {
    marsRover._direction = W;
    marsRover.backward();
    marsRover.backward();
    assert(marsRover.pos.x === 2);
    assert(marsRover.pos.y === 0);
    marsRover._direction = N;
    marsRover.backward();
    marsRover.backward();
    marsRover.backward();
    assert(marsRover.pos.x === 2);
    assert(marsRover.pos.y === 3);
  });

  it('can turn left', function () {
    marsRover.turn(LEFT);
    assert(marsRover._direction === W);
    marsRover.turn(LEFT);
    assert(marsRover._direction === S);
    marsRover.turn(LEFT);
    assert(marsRover._direction === E);
    marsRover.turn(LEFT);
    assert(marsRover._direction === N);
    marsRover.turn(LEFT);
    assert(marsRover._direction === W);
  });

  it('can turn right', function () {
    marsRover.turn(RIGHT);
    assert(marsRover._direction === N);
    marsRover.turn(RIGHT);
    assert(marsRover._direction === E);
    marsRover.turn(RIGHT);
    assert(marsRover._direction === S);
    marsRover.turn(RIGHT);
    assert(marsRover._direction === W);
    marsRover.turn(RIGHT);
    assert(marsRover._direction === N);
  });

  it('receives a character array of commands', function () {
    marsRover._direction = S;
    marsRover.execute(['f', 'b', 'left', 'left', 'f', 'b', 'right']);
    assert(marsRover.pos.x === 2);
    assert(marsRover.pos.y === 3);
    assert(marsRover._direction === N);
  });
});
