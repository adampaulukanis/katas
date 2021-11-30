/* jshint node: true, esversion: 6 */
'use strict';

const N = 0,
  S = 180,
  E = 90,
  W = 270;
const LEFT = -90;
const RIGHT = 90;

class Rover {
  constructor(x = 0, y = 0) {
    this.pos = {};
    this.pos.x = x;
    this.pos.y = y;

    this._direction = S;
  }

  execute(commands = []) {
    commands.forEach((cmd) => {
      switch (cmd) {
        case 'f': // forward
          this.forward();
          break;
        case 'b':
          this.backward();
          break;
        case 'left':
          this.turn(LEFT);
          break;
        default:
          throw new Error(`Method "${cmd}" not implemented`);
      }
    });
    return this;
  }

  forward() {
    // take into account the rover's direction
    let dir = this._direction;
    if (dir === N) {
      this.pos.y -= 1;
    } else if (dir === S) {
      this.pos.y += 1;
    } else if (dir === E) {
      this.pos.x += 1;
    } else {
      this.pos.x -= 1;
    }
    return this;
  }

  backward() {
    // take into account the rover's direction
    let dir = this._direction;
    if (dir === N) {
      this.pos.y += 1;
    } else if (dir === S) {
      this.pos.y -= 1;
    } else if (dir === E) {
      this.pos.x -= 1;
    } else {
      this.pos.x += 1;
    }
    return this;
  }

  turn(to) {
    if (this._direction === 0) this._direction = 360;
    this._direction += to;
    this._direction %= 360;
    return this;
  }
}

module.exports = Rover;
