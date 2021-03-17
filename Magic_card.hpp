#pragma once
#pragma warning(disable : 4996)
#pragma warning(disable : 26812) //disables warning for 'enum class' instead of just 'enum'

enum Type {
	unknown,
	trap,
	buff,
	spell
};

class Magic_card {
public:

	Magic_card();
	Magic_card(const char*, const char*, const Type);
	const char* getName() const;
	const char* getEffect() const;
	Type getType() const;
	bool get_isEmpty_magic() const;
	void setName(const char*);
	void setEffect(const char*);
	void setType(const Type);
	void set_isEmpty_magic(const bool);

	~Magic_card() {};

private:
	char name[26];
	char effect[101];
	Type type;
	bool isEmpty;
};
