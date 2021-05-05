var fs = require('fs');
var mod = require('bindings')('verthash-pospace.node')

console.log("Testing Verthash")
var datfile = fs.readFileSync('./verthash.dat')
var teststart = Buffer.from('000000203a297b4b7685170d7644b43e5a6056234cc2414edde454a87580e1967d14c1078c13ea916117b0608732f3f65c2e03b81322efc0a62bcee77d8a9371261970a58a5a715da80e031b02560ad8');
var result = mod.hash(datfile, teststart);
console.log(result.toString('hex'));

