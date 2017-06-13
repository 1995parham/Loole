/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 13-06-2017
 * |
 * | File Name:     index.js
 * +===============================================
 */
const loole = require('./build/Release/loole');

module.exports = {
  createPipe(callback) {
    return new Promise((resolve, reject) => {
      loole.createPipe((err, fd1, fd2) => {
        if (err) {
          if (callback) {
            callback(err);
          }
          return reject(err);
        }
        fds = [fd1, fd2];
        if (callback) {
          callback(null, fds);
        }
        return resolve(fds);
      });
    });
  },
  unlinkFifo(path) {
    loole.unlinkFifo(path);
  },
  createFifo(path, callback) {
    return new Promise((resolve, reject) => {
      loole.createFifo(path, (err) => {
        if (err) {
          if (callback) {
            callback(err);
          }
          return reject(err);
        }
        if (callback) {
          callback(null);
        }
        return resolve();
      });
    });
  }
}
