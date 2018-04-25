const https = require('https');

https
  .get('https://lemoineolivier35@gmail.com:VyZw9dWWj%&cmVlTAuvGJKbmyaW&8d@api.openstreetmap.org/api/0.6/permissions/', resp => {
    let data = '';

    // A chunk of data has been recieved.
    resp.on('data', chunk => {
      data += chunk;
    });

    // The whole response has been received. Print out the result.
    resp.on('end', () => {
      console.log(JSON.parse(data).explanation);
    });
  })
  .on('error', err => {
    console.log('Error: ' + err.message);
  });
