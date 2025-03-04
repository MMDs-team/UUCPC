echo "Generating input files..."
for input_generator in generate_in*
do
	echo "Executing $input_generator"
	py $input_generator
	echo "Executing $input_generator -> Done!"
	echo ""
done
echo "Generating input files -> Done!"
echo "----------------------------------------"

echo "Generating output files..."
py generate_out.py solution.cpp
echo "Generating output files -> Done!"
