
dataset_size = 100;
max_value = 100;
aaa = Array.new(dataset_size);
bbb = Array.new(dataset_size);
ccc = [];
k = 0;
idx = 0;
total = 0;

0.upto(dataset_size-1) do |idx|
	aaa[idx] = rand(max_value)
end;
puts aaa;

k = aaa.max;
ccc = Array.new(k+1);
0.upto(k){|idx| ccc[idx]=0;}
puts "#{ccc.length}, the length of ccc";

0.upto(dataset_size-1) do |idx|
	ccc[aaa[idx]] += 1;
end;

total = 0;
0.upto(k){ |idx| total += ccc[idx]; ccc[idx] = total;}

aaa.reverse.each { |idx| bbb[ccc[idx]] = idx; ccc[idx] -= 1;}

puts bbb;
