#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <string>
#include <climits>
#include <vector>
#include <queue>

using namespace std;
using namespace sf;

vector<vector<int>> temp_matrix;
vector<vector<int>> graf_matrix;
vector<pair<int, int>> paths;
vector<int> temp_vertexs;
Font text_font;


int WINDOW_W = 1300;
int WINDOW_H = 700;

template<class T>
class Graph
{
private:
	int maxSize;
	queue<T> VertsQueue;
public:
	vector<vector<int>> matrix;
	vector<T> vertexList;
	Graph() : Graph(20) {}
	Graph(const int& size) {
		maxSize = size;
		matrix = vector<vector<T>>(size, vector<T>(size));
		for (int i = 0; i < maxSize; ++i) {
			for (int j = 0; j < maxSize; ++j)
				matrix[i][j] = 0;
		}
	}

	vector<T> GetList() {
		return vertexList;
	}
	bool isFull() {
		return vertexList.size() == maxSize;
	}
	bool isEmpty() {
		return vertexList.size() == 0;
	}
	void ReadyaddVertex(const T& vertex) {
		if (isFull()) {
			cout << "Кол-во вершин превышает максимум." << endl;
			return;
		}
		vertexList.push_back(vertex);
		temp_vertexs.push_back(vertex);
	}
	void addVertex(const T& vertex) {
		if (isFull()) {
			cout << "Кол-во вершин превышает максимум." << endl;
			return;
		}
		vertexList.push_back(vertex);
		temp_vertexs.push_back(vertex);
		int vertPos1 = GetPos(vertex);
		for (int i = 0; i < vertexList.size(); ++i) {
			matrix[i][vertPos1] = 0;
			matrix[vertPos1][i] = 0;
		}
	}
	int GetPos(const T& v) {
		for (int i = 0; i < vertexList.size(); ++i) {
			if (vertexList[i] == v) {
				return i;
			}
		}
		return -1;
	}
	int GetAmount() {
		return vertexList.size();
	}
	int GetWeight(const T& vfirst, const T& vsecond) {
		if (isEmpty()) {
			return 0;
		}
		int Pos_vfirst = GetPos(vfirst);
		int Pos_vsecond = GetPos(vsecond);
		if (Pos_vfirst == -1 || Pos_vsecond == -1) {
			cout << "Нет узла в графе " << endl;
			return 0;
		}
		return matrix[Pos_vfirst][Pos_vsecond];
	}
	vector<T> GetAdjVert(const T& vertex) {
		vector<T> AdjVertList;
		int pos = GetPos(vertex);
		if (pos != -1) {
			for (int i = 0; i < vertexList.size(); ++i) {
				if (matrix[pos][i] != 0) {
					AdjVertList.push_back(vertexList[i]);
				}
			}
		}
		return AdjVertList;
	}
	//ориентированный или нет
	void AddEdge(const T& vertex1, const T& vertex2, int weight) {
		if (GetPos(vertex1) != (-1) && GetPos(vertex2) != (-1)) {
			int vertPos1 = GetPos(vertex1);
			int vertPos2 = GetPos(vertex2);

			if (matrix[vertPos1][vertPos2] != 0 && matrix[vertPos2][vertPos1] != 0) {
				cout << "Ребро уже есть" << endl;
				return;
			}
			else {
				matrix[vertPos1][vertPos2] = weight;   //1 для ориентированного графа
				matrix[vertPos2][vertPos1] = weight; //1,2 для неориентированного графа

			}
		}
		else {
			cout << "Одной из вершин нет в графе" << endl;
			return;
		}

	}
	//ориентированный или нет
	void DeleteEdge(const T& vertex1, const T& vertex2) {
		if (GetPos(vertex1) != (-1) && GetPos(vertex2) != (-1)) {
			int vertPos1 = GetPos(vertex1);
			int vertPos2 = GetPos(vertex2);

			if (matrix[vertPos1][vertPos2] != 0 && matrix[vertPos2][vertPos1] != 0) {
				matrix[vertPos1][vertPos2] = 0;   //1 для ориентированного графа
				matrix[vertPos2][vertPos1] = 0; //1,2 для неориентированного графа
				return;
			}

		}
		else {
			cout << "Одной из вершин нет в графе" << endl;
			return;
		}

	}
	//неориентированный
	void DeleteVertex(const T& vertex1) {
		vector<T> AdjVert = GetAdjVert(vertex1);
		int vertPos1 = GetPos(vertex1);
		matrix.erase(matrix.begin() + vertPos1);
		for (int i = 0; i < matrix.size(); ++i) {
			matrix[i].erase(matrix[i].begin() + vertPos1);
		}
		auto it = remove(vertexList.begin(), vertexList.end(), vertex1);
		vertexList.erase(it, vertexList.end());
		auto tit = remove(temp_vertexs.begin(), temp_vertexs.end(), vertex1);
		temp_vertexs.erase(tit, temp_vertexs.end());
		for (int i = 0; i < vertexList.size(); ++i) {
			vertexList[i] = i + 1;
		}


	}
	void PrintMatrix() {
		if (!isEmpty()) {
			cout << endl;
			cout << "Матрица смежности: " << endl;
			cout << "-  ";
			for (int i = 0; i < vertexList.size(); ++i) {
				cout << vertexList[i] << "  ";
			}
			cout << endl;
			for (int i = 0; i < vertexList.size(); ++i) {
				cout << vertexList[i] << " ";
				for (int j = 0; j < vertexList.size(); ++j) {
					cout << " " << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "Граф пуст" << endl;
		}
	}
	//ориентированный или нет
	int GetAmountEdges() {
		int amount = 0;
		if (!isEmpty()) {
			for (int i = 0; i < vertexList.size(); ++i) {
				for (int j = 0; j < vertexList.size(); ++j) {
					if (matrix[i][j] != 0) {
						amount++;
					}
				}
			}
		}
		//return amount;        //для ориентированного графа
		return amount / 2;  //для неориентированного графа
	}
	void DFS(T& start, bool* visited) {
		cout << "Вершина " << start << " пройдена" << endl;
		visited[GetPos(start)] = true;
		vector<T> AdjVert = GetAdjVert(start);
		for (int i = 0; i < AdjVert.size(); ++i) {
			if (!visited[GetPos(AdjVert[i])]) {
				DFS(AdjVert[i], visited);
			}
		}
	}
	void simplePathfindingAlgoritm(int vertex1)
	{
		int start = GetPos(vertex1);
		bool* Visited = new bool[vertexList.size()];
		unsigned* distances = new unsigned[vertexList.size()];
		unsigned minimalWeight, minimalIndex;

		for (unsigned i = 0; i < vertexList.size(); ++i)
		{
			Visited[i] = false;
			distances[i] = INT_MAX;
		}

		distances[start] = 0;

		do
		{
			minimalIndex = INT_MAX;
			minimalWeight = INT_MAX;

			for (unsigned i = 0; i < vertexList.size(); ++i)
			{
				if (!Visited[i] && distances[i] < minimalWeight)
				{
					minimalIndex = i;
					minimalWeight = distances[i];
				}
			}

			if (minimalIndex != INT_MAX)
			{
				for (unsigned i = 0; i < vertexList.size(); ++i)
				{
					if (matrix[minimalIndex][i])
					{
						unsigned temp = minimalWeight + matrix[minimalIndex][i];

						if (temp < distances[i])
							distances[i] = temp;
					}
				}

				Visited[minimalIndex] = true;
			}
		} while (minimalIndex < INT_MAX);

		for (unsigned i = 0; i < vertexList.size(); ++i)
		{
			if (distances[i] != INT_MAX)
			{
				cout << "Вес: " << start << " ~> " << i << " = " << setw(6) << left << distances[i] << "\t";

				unsigned end = i;
				unsigned weight = distances[end];
				string way = to_string(end) + " >~ ";

				while (end != start)
				{
					for (unsigned j = 0; j < vertexList.size(); ++j)
					{
						if (matrix[j][end])
						{
							int temp = weight - matrix[j][end];

							if (temp == distances[j])
							{
								end = j;
								weight = temp;
								way += to_string(j) + " >~ ";
							}
						}
					}
				}

				cout << "Путь: ";

				for (int j = way.length() - 5; j >= 0; --j)
					cout << way[j];

				cout << endl;
			}
			else
				cout << "Вес: " << start << " ~ " << i << " = " << "маршрут недоступен" << endl;
		}
		delete[] Visited;
		delete[] distances;
	}
};
void specialMatrix(vector<vector<int> > matrix) {
	int amount = matrix.size();
	temp_matrix.clear();
	graf_matrix.clear();
	vector<int> temp_vec;
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++)
			if (i == j)
				temp_vec.push_back(-1);
			else
				temp_vec.push_back(matrix[i][j]);
		temp_matrix.push_back(temp_vec);
		temp_vec.clear();
	}
	for (int i = 0; i < amount; i++) {
		for (int j = 0; j < amount; j++)
			temp_vec.push_back(matrix[i][j]);
		graf_matrix.push_back(temp_vec);
		temp_vec.clear();
	}
}
void reductionRow()
{
	int amount = temp_matrix.size();
	int size = amount;
	for (int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < size; j++)
		{
			if (temp_matrix[i][j] < min && temp_matrix[i][j] != -1)
				min = temp_matrix[i][j];
		}

		if (min != INT_MAX && min != 0)
		{
			for (int j = 0; j < size; j++)
			{
				if (temp_matrix[i][j] > 0 && temp_matrix[i][j] != INT_MAX)
					temp_matrix[i][j] -= min;
			}
		}
	}
}
void reductionColumn()
{
	int amount = temp_matrix.size();
	int size = amount;
	for (int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		for (int j = 0; j < size; j++)
		{
			if (temp_matrix[j][i] < min && temp_matrix[j][i] != -1)
				min = temp_matrix[j][i];
		}

		if (min != INT_MAX && min != 0)
		{
			for (int j = 0; j < size; j++)
			{
				if (temp_matrix[j][i] > 0 && temp_matrix[j][i] != INT_MAX)
					temp_matrix[j][i] -= min;
			}
		}
	}
}
int getMinRow(int h, int g)
{
	int amount = temp_matrix.size();
	int min = INT_MAX;
	for (int i = 0; i < amount; i++)
	{
		if (temp_matrix[h][i] < min && i != g && temp_matrix[h][i] != -1)
			min = temp_matrix[h][i];
	}
	return min;
}
int getMinColumn(int h, int g)
{
	int amount = temp_matrix.size();
	int min = INT_MAX;
	for (int i = 0; i < amount; i++)
	{
		if (temp_matrix[i][g] < min && i != h && temp_matrix[i][g] != -1)
			min = temp_matrix[i][g];
	}
	return min;
}
pair<int, int> getPaths()
{
	int amount = temp_matrix.size();
	int max = INT_MIN;
	int size = amount;
	vector<vector < int>> cop = temp_matrix;
	std::pair<int, int> way;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp_matrix[i][j] == 0)
			{
				int mark = getMinRow(i, j) + getMinColumn(i, j);
				if (max < mark)
				{
					max = mark;
					way.first = i;
					way.second = j;
				}
			}
		}
	}

	if (temp_matrix[way.second][way.first] == 0)
		temp_matrix[way.second][way.first] = -1;


	for (int i = 0; i < size; i++)
	{
		temp_matrix[way.first][i] = -1;
		temp_matrix[i][way.second] = -1;
	}
	return way;
}
void branchAndBoundMethod()
{
	int amount = temp_matrix.size();
	temp_matrix = graf_matrix;
	for (int i = 0; i < amount; i++)
		for (int j = 0; j < amount; j++)
		{
			if (i == j)
				temp_matrix[i][j] = -1;
			if (temp_matrix[i][j] <= 0)
				temp_matrix[i][j] = -1;
		}

	int ii = 0;
	while (ii != amount)
	{
		reductionRow();
		reductionColumn();
		std::pair<int, int> tmp;
		tmp = getPaths();
		if (tmp != std::pair<int, int>(0, 0))
			paths.push_back(tmp);
		ii++;
	}
}
void printRoad() {
	cout << "Лучший маршрут:\n";
	int begin = 0;
	for (int i = 0; i < paths.size(); i++) {
		for (int j = 0; j < paths.size(); j++) {
			if (paths[j].first == begin) {
				cout << paths[j].first + 1;
				cout << " ~> ";
				begin = paths[j].second;
				break;
			}
		}
	}
	bool lastElementPrinted = false;
	for (int j = 0; j < paths.size(); j++)
		if (paths[j].first == begin) {
			cout << paths[j].first + 1;
			lastElementPrinted = true;
			break;
		}
	if (!lastElementPrinted) {
		for (int j = 0; j < paths.size(); j++)
			if (paths[j].second == begin)
				cout << paths[j].second + 1;
	}
	bool hasRoad = false;
	for (int i = 0; i < paths.size(); i++)
		if (paths[i].second == 0) {
			hasRoad = true;
			break;
		}
	if (!hasRoad)
		cout << "\nЗадача не имеет решения\n";
	cout << endl;
}
void printPaths(vector<vector<int> > matrix) {
	cout << "Пути из одной вершины в другую:" << endl;
	for (int i = 0; i < paths.size(); i++)
		cout << paths[i].first + 1 << " ~> " << paths[i].second + 1
		<< " = " << matrix[paths[i].first][paths[i].second] << endl;
}
void summaPaths(vector<vector<int> > matrix) {
	int sum = 0;
	cout << "Длина маршрута:\n";
	for (int i = 0; i < paths.size(); i++)
		sum += matrix[paths[i].first][paths[i].second];
	cout << sum << endl;
}
class Node {
public:
	Text nodename;
	string strname;
	CircleShape circle;
	int x;
	int y;
	int rad;
	int xname;
	int yname;
	Node() {
		xname = x + rad;
		yname = y + rad;
	}
};
class Line {
public:
	Text name;
	string strname;
	vector<Vertex> linest;
	int x1;
	int y1;
	int x2;
	int y2;
	Line() {

	}
};
void setCoord(int i, int amountVert, vector<Node>& cities, Graph<int> graph)
{
	Node city;
	int R_;

	int x0 = WINDOW_W / 2;
	int y0 = WINDOW_H / 2;
	if (WINDOW_W > WINDOW_H)
	{
		city.rad = 5 * (WINDOW_H / 20) / amountVert;
		R_ = WINDOW_H / 2 - city.rad - 75;
	}
	else {
		city.rad = 5 * (WINDOW_W / 20) / amountVert;
		R_ = WINDOW_W / 2 - city.rad - 15;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(amountVert);
	city.x = R_ * cos(theta) + y0 + R_;
	city.y = R_ * sin(theta) + x0 - R_ - city.rad;
	city.xname = city.x + city.rad;
	city.yname = city.y + city.rad;
	city.circle.setPosition(city.x, city.y);
	city.circle.setFillColor(Color(65, 105, 225));
	city.circle.setRadius(city.rad);
	city.circle.setOutlineThickness(4);
	city.circle.setOutlineColor(Color::Black);
	city.nodename.setFont(text_font);
	city.nodename.setCharacterSize(20);
	city.nodename.setStyle(Text::Bold);
	city.nodename.setFillColor(sf::Color::Yellow);
	city.nodename.setPosition(city.xname - 7, city.yname - 17);
	city.nodename.setString(to_string(graph.vertexList[i]));
	city.strname = (to_string(graph.vertexList[i]));
	cities.push_back(city);
}
int getValue()
{
	while (true) // Цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		std::cout << "Введите целое значение: ";

		int a;
		bool flag = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (str.at(i) != '0' && str.at(i) != '1' && str.at(i) != '2' && str.at(i) != '3' && str.at(i) != '4' &&
				str.at(i) != '5' && str.at(i) != '6' && str.at(i) != '7' && str.at(i) != '8' && str.at(i) != '9' && str.at(i) != '.')
			{
				flag = false;
				std::cin.ignore(32767, '\n');
				break;
			}
		}
		if (flag)
		{
			a = atof(str.c_str());
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//Declare a Font object
	Font font;
	//Load and check the availability of the font file
	if (!text_font.loadFromFile("arialmt.ttf"))
	{
		cout << "can't load font" << endl;
	}

	vector<Line> connections;
	vector<Line> bestconnections;
	vector<Node> cities;
	
	Graph<int> graph;

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	const float W = 150;
	const float H = 40;
	const float fy = 50;
	const float ax = 50;
	const float ter = 25;

	RectangleShape back(Vector2f(W + (W + ter) * 6 + 20, fy + 20));
	back.move(ax - 10, fy - 15);
	back.setFillColor(Color::Cyan);
	back.setOutlineThickness(4.0f);
	back.setOutlineColor(Color::Blue);

	float AnswerW = W;
	float AnswerH = H;
	float Answerx = ax + (W + ter) * 2;
	float Answery = fy;
	RectangleShape Answer(Vector2f(AnswerW, AnswerH));
	Answer.move(Answerx, Answery);
	Answer.setFillColor(Color::White);
	Answer.setOutlineThickness(2.f);
	Answer.setOutlineColor(Color(0, 0, 0));
	Text TextAnswer;
	TextAnswer.setFont(text_font);
	TextAnswer.setCharacterSize(30);
	TextAnswer.setFillColor(sf::Color::Black);
	TextAnswer.setPosition(Answerx + 22, Answery);
	TextAnswer.setString("RESULT");


	float DrawW = W;
	float DrawH = H;
	float Drawx = ax + W + ter;
	float Drawy = fy;
	RectangleShape Draw(Vector2f(DrawW, DrawH));
	Draw.move(Drawx, Drawy);
	Draw.setFillColor(Color::White);
	Draw.setOutlineThickness(2.f);
	Draw.setOutlineColor(Color(0, 0, 0));
	Text TextDraw;
	TextDraw.setFont(text_font);
	TextDraw.setCharacterSize(30);
	TextDraw.setFillColor(sf::Color::Black);
	TextDraw.setPosition(Drawx + 5, Drawy);
	TextDraw.setString("PRINT");

	float NewW = W;
	float NewH = H;
	float Newx = ax;
	float Newy = fy;
	RectangleShape New(Vector2f(NewW, NewH));
	New.move(Newx, Newy);
	New.setFillColor(sf::Color::White);
	New.setOutlineThickness(2.f);
	New.setOutlineColor(Color(0, 0, 0));
	Text TextNew;
	TextNew.setFont(text_font);
	TextNew.setCharacterSize(30);
	TextNew.setFillColor(sf::Color::Black);
	TextNew.setPosition(Newx + 5, Newy);
	TextNew.setString("CREATE");

	float AddW = W;
	float AddH = H;
	float Addx = ax + (W + ter) * 3;
	float Addy = fy;
	RectangleShape Add(Vector2f(AddW, AddH));
	Add.move(Addx, Addy);
	Add.setFillColor(sf::Color::White);
	Add.setOutlineThickness(2.f);
	Add.setOutlineColor(Color(0, 0, 0));
	Text TextAdd;
	TextAdd.setFont(text_font);
	TextAdd.setCharacterSize(30);
	TextAdd.setFillColor(sf::Color::Black);
	TextAdd.setPosition(Addx + 7, Addy);
	TextAdd.setString("ADD NODE");

	float DelW = W;
	float DelH = H;
	float Delx = ax + (W + ter) * 4;
	float Dely = fy;
	RectangleShape Del(Vector2f(DelW, DelH));
	Del.move(Delx, Dely);
	Del.setFillColor(sf::Color::White);
	Del.setOutlineThickness(2.f);
	Del.setOutlineColor(Color(0, 0, 0));
	Text TextDel;
	TextDel.setFont(text_font);
	TextDel.setCharacterSize(30);
	TextDel.setFillColor(sf::Color::Black);
	TextDel.setPosition(Delx + 12, Dely);
	TextDel.setString("DEL NODE");

	float DelEdgeW = W;
	float DelEdgeH = H;
	float DelEdgex = ax + (W + ter) * 6;
	float DelEdgey = fy;
	RectangleShape DelEdge(Vector2f(DelEdgeW, DelEdgeH));
	DelEdge.move(DelEdgex, DelEdgey);
	DelEdge.setFillColor(sf::Color::White);
	DelEdge.setOutlineThickness(2.f);
	DelEdge.setOutlineColor(Color(0, 0, 0));
	Text TextDelEdge;
	TextDelEdge.setFont(text_font);
	TextDelEdge.setCharacterSize(30);
	TextDelEdge.setFillColor(sf::Color::Black);
	TextDelEdge.setPosition(DelEdgex + 10, DelEdgey);
	TextDelEdge.setString("DEL EDGE");

	float AddEdgeW = W;
	float AddEdgeH = H;
	float AddEdgex = ax + (W + ter) * 5;
	float AddEdgey = fy;

	RectangleShape AddEdge(Vector2f(AddEdgeW, AddEdgeH));
	AddEdge.move(AddEdgex, AddEdgey);
	AddEdge.setFillColor(sf::Color::White);
	AddEdge.setOutlineThickness(2.f);
	AddEdge.setOutlineColor(Color(0, 0, 0));
	Text TextAddEdge;
	TextAddEdge.setFont(text_font);
	TextAddEdge.setCharacterSize(30);
	TextAddEdge.setFillColor(sf::Color::Black);
	TextAddEdge.setPosition(AddEdgex + 10, AddEdgey);
	TextAddEdge.setString("ADD EDGE");

	RenderWindow MainWindow(VideoMode(WINDOW_W, WINDOW_H), "TRAVELLING SALESMAN", Style::Default, settings);
	while (MainWindow.isOpen()) {
		Event event;
		while (MainWindow.pollEvent(event)) {
			Vector2i position = Mouse::getPosition(MainWindow);
			int x = position.x;
			int y = position.y;
			if (x > 0 && y > 0 && x >= Answerx && x <= Answerx + AnswerW && y >= Answery && y <= Answery + AnswerH) {
				Answer.setFillColor(Color(0, 250, 154));
			}
			else if (x > 0 && y > 0 && x >= Newx && x <= Newx + NewW && y >= Newy && y <= Newy + NewH) {
				New.setFillColor(Color(0, 250, 154));
			}
			else if (x > 0 && y > 0 && x >= Drawx && x <= Drawx + DrawW && y >= Drawy && y <= Drawy + DrawH) {
				Draw.setFillColor(Color(0, 250, 154));;
			}
			else if (x > 0 && y > 0 && x >= Addx && x <= Addx + AddW && y >= Addy && y <= Addy + AddH) {
				Add.setFillColor(Color(0, 250, 154));;
			}
			else if (x > 0 && y > 0 && x >= Delx && x <= Delx + DelW && y >= Dely && y <= Dely + DelH) {
				Del.setFillColor(Color(0, 250, 154));;
			}
			else if (x > 0 && y > 0 && x >= DelEdgex && x <= DelEdgex + DelEdgeW && y >= DelEdgey && y <= DelEdgey + DelEdgeH) {
				DelEdge.setFillColor(Color(0, 250, 154));
			}
			else if (x > 0 && y > 0 && x >= AddEdgex && x <= AddEdgex + AddEdgeW && y >= AddEdgey && y <= AddEdgey + AddEdgeH) {
				AddEdge.setFillColor(Color(0, 250, 154));;
			}

			else {
				Answer.setFillColor(sf::Color::White);
				New.setFillColor(sf::Color::White);
				Draw.setFillColor(sf::Color::White);
				Add.setFillColor(sf::Color::White);
				Del.setFillColor(sf::Color::White);
				DelEdge.setFillColor(sf::Color::White);
				AddEdge.setFillColor(sf::Color::White);
			}
			switch (event.type) {
			case Event::MouseButtonPressed:

				if (event.key.code == Mouse::Left)
				{
					Vector2i position = Mouse::getPosition(MainWindow);
					int x = position.x;
					int y = position.y;

					if (x > 0 && y > 0 && x >= Answerx && x <= Answerx + AnswerW && y >= Answery && y <= Answery + AnswerH) {

						vector<vector<int>> tcopyMatrix;
						vector<vector<int>> tgrafMatrix;
						vector<pair<int, int>> tlist_for_paths;
						specialMatrix(graph.matrix);
						branchAndBoundMethod();
						printPaths(graph.matrix);
						cout << endl;
						printRoad();
						summaPaths(graph.matrix);
						for (int i = 0; i < paths.size(); i++) {

							Line connect;
							connect.x1 = cities[graph.GetPos(paths[i].first + 1)].xname;
							connect.y1 = cities[graph.GetPos(paths[i].first + 1)].yname;
							connect.x2 = cities[graph.GetPos(paths[i].second + 1)].xname;
							connect.y2 = cities[graph.GetPos(paths[i].second + 1)].yname;
							connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color(255, 69, 0)));
							connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color(255, 69, 0)));
							bestconnections.push_back(connect);
						}
						graf_matrix.clear();
						temp_matrix.clear();
						paths.clear();
					}
					if (x > 0 && y > 0 && x >= Newx && x <= Newx + NewW && y >= Newy && y <= Newy + NewH) {
						vector<Line> tempconnections;
						vector<Line> tempbestconnections;
						vector<Node> tempcities;
						Graph<int> tempgraph;
						int amountVert, amountEdge, edgeWeight;
						int vertex, initialVertex, endVertex;
						int answer = 0;
						while (answer != 1 && answer != 2) {
							cout << "Создать матрицу по-умолчанию? Если да, введите - 1, если нет - 2: "; answer = getValue();

						}
						if (answer == 2) {
							cout << "Введите кол-во вершин графа: ";
							amountVert = getValue();

							cout << "Введите кол-во ребер графа: "; amountEdge = getValue();;
							for (int i = 0; i < amountVert; ++i) {
								tempgraph.addVertex(i + 1);
								cout << "Вершина " << i + 1 << " создана" << endl;
								setCoord(i, amountVert, tempcities, tempgraph);
							}
							for (int i = 0; i < amountEdge; ++i) {
								cout << "Исходная вершина: "; initialVertex = getValue();;
								cout << "Конечная вершина: "; endVertex = getValue();;
								cout << "Вес ребра: "; edgeWeight = getValue();;
								tempgraph.AddEdge(initialVertex, endVertex, edgeWeight);
								Line connect;
								connect.x1 = tempcities[tempgraph.GetPos(initialVertex)].xname;
								connect.y1 = tempcities[tempgraph.GetPos(initialVertex)].yname;
								connect.x2 = tempcities[tempgraph.GetPos(endVertex)].xname;
								connect.y2 = tempcities[tempgraph.GetPos(endVertex)].yname;
								connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
								connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
								connect.name.setFont(text_font);
								connect.name.setCharacterSize(25);
								connect.name.setFillColor(sf::Color::Black);
								connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0);
								connect.name.setString(to_string(edgeWeight));
								tempconnections.push_back(connect);
							}
							graph = tempgraph;
							connections = tempconnections;
							bestconnections = tempbestconnections;
							cities = tempcities;
						}
						if (answer == 1) {
							amountVert = 6;
							for (int i = 0; i < amountVert; ++i) {
								tempgraph.ReadyaddVertex(i + 1);
								setCoord(i, amountVert, tempcities, tempgraph);

							}

							tempgraph.AddEdge(1, 2, 34);
							tempgraph.AddEdge(1, 3, 8);
							tempgraph.AddEdge(1, 5, 2);
							tempgraph.AddEdge(1, 6, 21);
							tempgraph.AddEdge(2, 3, 57);
							tempgraph.AddEdge(2, 4, 45);
							tempgraph.AddEdge(2, 5, 5);
							tempgraph.AddEdge(4, 5, 3);
							tempgraph.AddEdge(5, 6, 13);

							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = tempgraph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = tempcities[i].xname;
										connect.y1 = tempcities[i].yname;
										connect.x2 = tempcities[j].xname;
										connect.y2 = tempcities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(text_font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										tempconnections.push_back(connect);
									}
								}
							}
							graph = tempgraph;
							connections = tempconnections;
							bestconnections = tempbestconnections;
							cities = tempcities;
						}
					}
					if (x > 0 && y > 0 && x >= Drawx && x <= Drawx + DrawW && y >= Drawy && y <= Drawy + DrawH) {
						graph.PrintMatrix();
					}
					if (x > 0 && y > 0 && x >= Addx && x <= Addx + AddW && y >= Addy && y <= Addy + AddH) {

						if (graph.vertexList.size() == 20) {
							cout << "Кол-во вершин превышает максимум (20)" << endl;
							break;
						}
						vector<Line> tempconnections;
						vector<Line> tempbestconnections;
						vector<Node> tempcities;
						Graph<int> tempgraph = graph;
						tempbestconnections = bestconnections;
						tempconnections = connections;
						if (graph.vertexList.size() != 0)graph.addVertex(*max_element(graph.vertexList.begin(), graph.vertexList.end()) + 1);
						if (graph.vertexList.size() == 0)graph.addVertex(graph.vertexList.size() + 1);
						int amountVert = graph.vertexList.size();
						cout << "Вершина " << graph.vertexList.size() << " создана" << endl;
						cities.clear();
						connections.clear();
						bestconnections.clear();
						for (int i = 0; i < amountVert; ++i) {
							setCoord(i, amountVert, cities, graph);
						}
						for (int i = 0; i < amountVert; i++)
						{
							for (int j = i + 1; j < amountVert; j++)
							{
								int a = graph.matrix[i][j];
								if (a != 0)
								{
									Line connect;
									connect.x1 = cities[i].xname;
									connect.y1 = cities[i].yname;
									connect.x2 = cities[j].xname;
									connect.y2 = cities[j].yname;
									connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
									connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
									connect.name.setFont(text_font);
									connect.name.setCharacterSize(25);
									connect.name.setFillColor(sf::Color::Black);
									connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
									connect.name.setString(to_string(a));
									connections.push_back(connect);
								}
							}
						}
					}
					if (x > 0 && y > 0 && x >= Delx && x <= Delx + DelW && y >= Dely && y <= Dely + DelH) {
						int delvert;
						if (graph.vertexList.empty()) {
							cout << "Вершин для удаления нет" << endl;
							break;
						}
						vector<Line> tempconnections;
						tempconnections = connections;
						connections.clear();
						cout << "Введите вершину, которую нужно удалить "; delvert = getValue();;
						bool t1 = false;
						for (int i = 0; i < graph.vertexList.size(); ++i) {
							if (graph.vertexList[i] == delvert)
								t1 = true;
						}
						if (!t1) {
							cout << "В графе нет данной вершины " << endl;
							cities.clear();
							connections.clear();
							bestconnections.clear();
							int amountVert = graph.vertexList.size();
							for (int i = 0; i < amountVert; ++i) {
								setCoord(i, amountVert, cities, graph);
							}
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = graph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = cities[i].xname;
										connect.y1 = cities[i].yname;
										connect.x2 = cities[j].xname;
										connect.y2 = cities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(text_font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										connections.push_back(connect);
									}
								}
							}
							break;
						}
						else {
							vector<int> xx;
							for (int i = 0; i < graph.vertexList.size(); ++i) {
								xx.push_back(graph.GetWeight(delvert, i));
							}
							int vertPos2 = graph.GetPos(delvert);
							for (auto i : tempconnections) {
								for (int j = 0; j < xx.size(); ++j) {
									if (i.strname == to_string(xx[j])) {

										tempconnections.erase(tempconnections.begin() + vertPos2);
										vertPos2 += 1;
									}
								}

							}
							for (int i = 0; i < graph.vertexList.size(); ++i) {
								graph.DeleteEdge(delvert, i);
							}
							int vertPos1 = graph.GetPos(delvert);
							graph.DeleteVertex(delvert);
							for (auto i : cities) {
								if (i.strname == to_string(delvert)) {

									cities.erase(cities.begin() + vertPos1);
									break;
								}
							}
							connections = tempconnections;
							cities.clear();
							connections.clear();
							bestconnections.clear();
							int amountVert = graph.vertexList.size();
							for (int i = 0; i < amountVert; ++i) {
								setCoord(i, amountVert, cities, graph);
							}
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = graph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = cities[i].xname;
										connect.y1 = cities[i].yname;
										connect.x2 = cities[j].xname;
										connect.y2 = cities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(text_font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										connections.push_back(connect);
									}
								}
							}
						}
					}
					if (x > 0 && y > 0 && x >= DelEdgex && x <= DelEdgex + DelEdgeW && y >= DelEdgey && y <= DelEdgey + DelEdgeH) {
						if (graph.vertexList.empty()) {
							cout << "Ребер для удаления нет" << endl;
							break;
						}
						if (graph.GetAmountEdges() == 0) {
							cout << "Ребер для удаления нет" << endl;
							break;
						}
						int deledge1, deledge2;
						cout << "Введите первую вершину ребра для удаления "; deledge1 = getValue();;
						cout << endl;
						cout << "Введите вторую вершину ребра для удаления "; deledge2 = getValue();;
						bool t1 = false;
						bool t2 = false;
						for (int i = 0; i < graph.vertexList.size(); ++i) {
							if (graph.vertexList[i] == deledge1)
								t1 = true;
							if (graph.vertexList[i] == deledge2)
								t2 = true;
						}
						if (!t1 || !t2) {
							cout << "В графе нет данного ребра" << endl;
							break;
						}
						else {
							graph.DeleteEdge(deledge1, deledge2);
							cities.clear();
							connections.clear();
							bestconnections.clear();
							int amountVert = graph.vertexList.size();
							for (int i = 0; i < amountVert; ++i) {
								setCoord(i, amountVert, cities, graph);
							}
							for (int i = 0; i < amountVert; i++)
							{
								for (int j = i + 1; j < amountVert; j++)
								{
									int a = graph.matrix[i][j];
									if (a != 0)
									{
										Line connect;
										connect.x1 = cities[i].xname;
										connect.y1 = cities[i].yname;
										connect.x2 = cities[j].xname;
										connect.y2 = cities[j].yname;
										connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
										connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
										connect.name.setFont(text_font);
										connect.name.setCharacterSize(25);
										connect.name.setFillColor(sf::Color::Black);
										connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0 + 2);
										connect.name.setString(to_string(a));
										connections.push_back(connect);
									}
								}
							}
						}

					}
					if (x > 0 && y > 0 && x >= AddEdgex && x <= AddEdgex + AddEdgeW && y >= AddEdgey && y <= AddEdgey + AddEdgeH) {
						if (graph.vertexList.empty()) {
							cout << "Вершин для добавления ребер нет" << endl;
							break;
						}


						int initialVertex, endVertex, edgeWeight;
						cout << "Исходная вершина: "; initialVertex = getValue();;
						cout << "Конечная вершина: "; endVertex = getValue();;
						cout << "Вес ребра: "; edgeWeight = getValue();;
						bool t1 = false;
						bool t2 = false;
						for (int i = 0; i < graph.vertexList.size(); ++i) {
							if (graph.vertexList[i] == initialVertex)
								t1 = true;
							if (graph.vertexList[i] == endVertex)
								t2 = true;
						}
						if (!t1 || !t2) {
							cout << "В графе нет данной вершины " << endl;
							break;
						}
						else {

							graph.AddEdge(initialVertex, endVertex, edgeWeight);
							Line connect;
							connect.x1 = cities[graph.GetPos(initialVertex)].xname;
							connect.y1 = cities[graph.GetPos(initialVertex)].yname;
							connect.x2 = cities[graph.GetPos(endVertex)].xname;
							connect.y2 = cities[graph.GetPos(endVertex)].yname;
							connect.linest.push_back(Vertex(Vector2f(connect.x1, connect.y1), Color::Black));
							connect.linest.push_back(Vertex(Vector2f(connect.x2, connect.y2), Color::Black));
							connect.name.setFont(text_font);
							connect.name.setCharacterSize(25);
							connect.name.setFillColor(sf::Color::Black);
							connect.name.setPosition((connect.x2 + connect.x1) / 2.0, (connect.y2 + connect.y1) / 2.0);
							connect.name.setString(to_string(edgeWeight));
							connections.push_back(connect);
						}
					}

					break;
				}
				else break;

			case Event::Closed:
				MainWindow.close();
				break;

			}
		}
		MainWindow.clear(Color::White);
		MainWindow.draw(back);
		MainWindow.draw(Answer);
		MainWindow.draw(TextAnswer);
		MainWindow.draw(Draw);
		MainWindow.draw(TextDraw);
		MainWindow.draw(New);
		MainWindow.draw(TextNew);
		MainWindow.draw(Add);
		MainWindow.draw(TextAdd);
		MainWindow.draw(Del);
		MainWindow.draw(TextDel);
		MainWindow.draw(DelEdge);
		MainWindow.draw(TextDelEdge);
		MainWindow.draw(AddEdge);
		MainWindow.draw(TextAddEdge);
		for (auto i : connections) {
			MainWindow.draw(&i.linest[0], i.linest.size(), Lines);
			MainWindow.draw(i.name);
		}
		for (auto i : bestconnections) {
			MainWindow.draw(&i.linest[0], i.linest.size(), Lines);
		}
		for (auto i : cities) {
			MainWindow.draw(i.circle);
			MainWindow.draw(i.nodename);
		}
		MainWindow.display();
	}
	return 0;
}

