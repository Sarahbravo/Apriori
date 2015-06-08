void formatData(string filename)
{
	string line;
	string loadLine;
	ifstream infile;
	ofstream nextfile;
	int count = 0;
	int id;
	int currentID;
	int value;
	int index = 0;

	rename(filename.c_str(), "data.txt");
	infile.open("data.txt");
	nextfile.open(filename);
	nextfile.close();
	nextfile.open(filename);

	currentID = 0;

	while (!infile.eof())
	{
		getline(infile, line);
		stringstream ss(line);
		ss >> id;

		if (id == currentID)
		{
			ss >> value;
			nextfile << " " << value;
		}
		else
		{
			++currentID;

			if (currentID != 1)
				nextfile << endl;

			nextfile << currentID;
			ss >> value;
			nextfile << " " << value;
		}
	}

	infile.close();
	nextfile.close();
}