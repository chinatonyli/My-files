require './string'

print "Please input your plain text: "
plain = gets.to_s.chop
print "Please input your key(included negatives): "
key = gets.to_i

plain.each_byte do |letter|
   if letter.chr.upcase?
       print ((letter - 'A'.byte + key) % 26 + 'A'.byte).chr
   elsif letter.chr.downcase?
       print ((letter - 'a'.byte + key) % 26 + 'a'.byte).chr
   else
       print letter.chr
   end
end
puts
