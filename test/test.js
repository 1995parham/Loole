const loole = require('..');
const fs = require('fs');
const child_process = require("child_process");


loole.createPipe('/tmp/Hello').then(() => {
  console.log('we have a new and ready pipe.');

  const cp1 = child_process.spawn('ls', ['-la']);
  cp1.stdout.pipe(fs.createWriteStream('/tmp/Hello'));

  const cp2 = child_process.spawn('cat', ['/tmp/Hello']);
  cp2.stdout.pipe(process.stdout);
});
