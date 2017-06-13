const loole = require('..');
const fs = require('fs');
const child_process = require("child_process");


loole.createFifo('/tmp/Hello').then(() => {
  console.log('we have a new and ready fifo.');

  const cp1 = child_process.spawn('ls', ['-la']);
  cp1.stdout.pipe(fs.createWriteStream('/tmp/Hello'));

  const cp2 = child_process.spawn('cat', ['/tmp/Hello']);
  cp2.stdout.pipe(process.stdout);
  cp2.stdout.on('end', () => {
    fs.unlinkSync('/tmp/Hello');
  });
});

loole.createPipe().then((fds) => {
  console.log(`we have a new and ready pipe on ${fds[0]}, ${fds[1]}`);

  const cp1 = child_process.spawn('ls', ['-la', '/var']);
  cp1.stdout.pipe(fs.createWriteStream(`/dev/fd/${fds[1]}`));

  const cp2 = child_process.spawn('cat', [`/dev/fd/${fds[0]}`]);
  cp2.stdout.pipe(process.stdout);
});
