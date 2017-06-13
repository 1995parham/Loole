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
  createPipe(path, callback) {
    return new Promise((resolve, reject) => {
      loole.createPipe(path, (err) => {
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
