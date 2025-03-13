echo "Generating input files..."
for input_generator in generate_in*
do
	echo "Executing $input_generator"
	python3 $input_generator
	echo "Executing $input_generator -> Done!"
	echo ""
done
echo "Generating input files -> Done!"
echo "----------------------------------------"

echo "Generating output files..."
python3 generate_out.py solution.cpp
echo "Generating output files -> Done!"

rm -f solver