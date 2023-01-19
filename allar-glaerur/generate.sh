foo()
{
	mkdir ${1:8:-1} -p
	for d in ${1}*/
	do
		ln $(pwd)/${d}pdf/glaerur.pdf $(pwd)/${d:8:-1}.pdf -s -f
	done
}

for d in ../efni/*/
do
	foo $d
done
