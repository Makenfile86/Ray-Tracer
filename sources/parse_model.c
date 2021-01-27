#include "rt.h"



 static void  read_obj(t_obj *obj, int fd)
{
    //int     fd;

    int     i;
 //char    *filename;
   
    char *line;
 

 

i = 0;
    //filename = "cat.obj";
//fd = open(filename, O_RDONLY);

	while ((get_next_line(fd, &line)) == 1)
	{
	
		if (ft_strncmp(line, "v ", 2) == 0)
			obj->num_geometry++;
        else if (ft_strncmp(line, "vt", 2) == 0)
			obj->num_coordinates++;
		else if (ft_strncmp(line, "vn", 2) == 0)
			obj->num_normals++;
		else if (ft_strncmp(line, "f ", 2) == 0)
			obj->num_polygonals++;
		free(line);

	}
	
malloc_obj(obj, obj->num_geometry, obj->num_coordinates);
malloc_obj2(obj, obj->num_normals, obj->num_polygonals);

}

static void	parse_poly(t_obj *obj, size_t i, char *line)
{
	char	**parts;
	char	**tf;
	size_t	n;
	size_t j;

	j = 0;

	parts = ft_strsplit(line + 1, ' ');
	while (parts[j] && (tf = ft_strsplit(parts[j], '/')))
	{
		if (!tf[0] || (n = ft_atoi(tf[0])))	
		obj->polygonals[i].ve[j] = obj->geometry[n - 1];
		if (!tf[1] || (n = ft_atoi(tf[1])))
		{
			
			obj->polygonals[i].uv[j] = obj->coordinates[n - 1];
			//ft_putnbr(obj->polygonals[i].no[j].z);
		}
		if (!tf[2] || (n = ft_atoi(tf[2])))
		{
			
			obj->polygonals[i].no[j] = obj->normals[n - 1];
			
		}
		//free(tf[0]);
		//free(tf[1]);
		//free(tf);
		//free(parts[j]);
		//, tf[0], tf[1], tf[2], tf, parts[j]);
		j++;
	}
	
	//free(parts);
		obj->polygonals[i].te[0] = vector_minus(obj->polygonals[i].ve[1], obj->polygonals[i].ve[0]);
	obj->polygonals[i].te[1] = vector_minus(obj->polygonals[i].ve[2], obj->polygonals[i].ve[1]);
	obj->polygonals[i].te[2] = vector_minus(obj->polygonals[i].ve[0], obj->polygonals[i].ve[2]);
	obj->polygonals[i].normal = obj->polygonals[i].no[0];
	
	//ft_putendl("tata se o");

	//triface_calc_bounds(&obj->polygonals[i]);

	//tasta puuttuu se yks funktio
	/*
	printf("%f x\n", obj->polygonals[0].normal.x);

		printf("%f y\n", obj->polygonals[0].normal.y);

		printf("%f z\n", obj->polygonals[0].normal.z);
		*/
		
}

void	malloc_obj(t_obj *obj, size_t num_geometry, size_t num_coordinates)
{
	obj->geometry = (t_vector*)malloc(sizeof(t_vector) * num_geometry);
	obj->coordinates = (t_vec2*)malloc(sizeof(t_vec2) * num_coordinates);
}
void	malloc_obj2(t_obj *obj, size_t num_normals, size_t num_polygonals)
{
	//ft_putendl("poly malloc");
//	ft_putnbr(num_polygonals);
	//ft_putchar('\n');
	obj->normals = (t_vector*)malloc(sizeof(t_vector) * num_normals);
	obj->polygonals = (t_vertices*)malloc(sizeof(t_vertices) * num_polygonals);
}

static void read_obj_data(int fd, t_obj *obj)
{
	char	*line;
	size_t	i[4];
	t_vector location;
double scale;
t_vector rotate;

rotate.x = 0;
rotate.y = 0;
rotate.z = 0;
	location.x = -12;
	location.y = 15;
	location.z = 38;

rotate.x = obj->model->rot[0].x;
rotate.y = obj->model->rot[0].y;
rotate.z = obj->model->rot[0].z;
	location.x = obj->model->xyz[0].x;
	location.y = obj->model->xyz[0].y;
	location.z = obj->model->xyz[0].z;
	scale = obj->model->size;
	//if (scale > 2.88)
	//scale = 2.88;
		scale = 2.5;




	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	ft_putendl("moikkaskhdsahidhsia");
	while (get_next_line(fd, &line) > 0)
	{

		if (ft_strncmp(line, "v ", 2) == 0)
			obj->geometry[i[0]++] = vec_rot_zyx(vectorscale(scale, vectoradd(parse_geo(line + 1), location)), rotate);
		if (ft_strncmp(line, "vt ", 2) == 0)
			obj->coordinates[i[1]++] = parse_coord(line + 1);
	if (ft_strncmp(line, "vn ", 2) == 0)
			obj->normals[i[2]++] = vec_rot_zyx(parse_normals(line + 2), rotate);
	if (ft_strncmp(line, "f ", 2) == 0)
			parse_poly(obj, i[3]++, line);
		free(line);
		
	}

	//	printf("%f x geometry	\n", obj->geometry[2].x);

	//	printf("%f y\n", obj->geometry[2].y);

	//	printf("%f z\n", obj->geometry[2].z);
	//printf("%f\n", obj->geometry[1].z);
//printf("%f\n", obj->coordinates[1].y);


}



t_vector	parse_normals(char *line)
{
	t_vector	vector;
	char *tmp;
	char *tmp2;
	char *tmp3;
	int	i;
	int k;

k = 0;
	i = 1;
tmp = (char *)malloc(sizeof(char) * 15);
tmp2 = (char *)malloc(sizeof(char) * 15);
tmp3 = (char *)malloc(sizeof(char) * 25);


		while (line[i] != ' ')
		{
		tmp[k] = line[i];
			i++;
			k++;
		}
		tmp[k] = '\0';
		i++;
		k = 0;
		while (line[i] != ' ')
		{
			tmp2[k] = line[i];
			i++;
			k++;
		}
		tmp2[k] = '\0';
		i++;
		k = 0;
		while (line[i] != '\0')
		{
			tmp3[k] = line[i];
			i++;
			k++;
		}
		tmp3[k] = '\0';
	
	vector.x = atof(tmp);
	vector.y = atof(tmp2);
	vector.z = atof(tmp3);
free(tmp3);
free(tmp2);
free(tmp);
	return (vector);

}

t_vec2	parse_coord(char *line)
{
	t_vec2	vector;
	char *tmp;
	char *tmp2;
	int	i;
	int k;

	k = 0;
	i = 1;
	tmp = (char *)malloc(sizeof(char) * 20);
tmp2 = (char *)malloc(sizeof(char) * 20);



	while (line[i] != ' ')
		{
			tmp[k] = line[i];
			i++;
			k++;
		}
		tmp[k] = '\0';
		i++;
		k = 0;
		while (line[i] != '\0')
		{
			tmp2[k] = line[i];
			i++;
			k++;
		}
		tmp2[k] = '\0';
		
	
	
	vector.u = atof(tmp2);
	vector.v = atof(tmp);

free(tmp2);
free(tmp);
	//printf("%f\n", vector.y);
	return (vector);



}

t_vector	parse_geo(char *line)
{
	t_vector	vector;
	char *tmp;
	char *tmp2;
	char *tmp3;
	int	i;
	int k;

tmp = (char *)malloc(sizeof(char) * 15);
tmp2 = (char *)malloc(sizeof(char) * 15);
tmp3 = (char *)malloc(sizeof(char) * 20);

k = 0;
	i = 1;


		while (line[i] != ' ')
		{
		tmp[k] = line[i];
			i++;
			k++;
		}
		tmp[k] = '\0';
		i++;
		k = 0;
		while (line[i] != ' ')
		{
			tmp2[k] = line[i];
			i++;
			k++;
		}
		tmp2[k] = '\0';
		i++;
		k = 0;
		while (line[i] != '\0')
		{
			tmp3[k] = line[i];
			i++;
			k++;
		}
		tmp3[k] = '\0';
	
	
	vector.x = atof(tmp);
	vector.y = atof(tmp2);
	vector.z = atof(tmp3);
	free(tmp3);
free(tmp2);
free(tmp);
	return (vector);

}
/*
t_obj    *create_obj_data(void)
{
    	t_obj *obj;

	if (!(obj = (t_obj*)malloc(sizeof(t_obj))))
	{
        		return (0);
	}
//	obj->num_geometry = 0;
//	m->vertices = NULL;

	return (obj);
}
*/


t_data  *init_obj(t_data *data)
{

 //t_obj *obj;
   int fd;

char *filename;

 
 
 //if ((ft_strcmp(data->obj->model->name, "diamond") == 0))
 filename = "diamond.obj";
 //else if ((ft_strcmp(data->obj->model->name, "cat") == 0))
 //filename = "cat.obj";
ft_putendl(filename);
   //if (!(obj = (t_obj*)malloc(sizeof(t_obj))))
	//{
        		//return (0);
	//}
//obj = create_obj_data();
	

fd = open(filename, O_RDONLY);
 read_obj(data->obj, fd);
 close (fd);
	fd = open(filename, O_RDONLY);




		read_obj_data(fd, data->obj);
		


	close(fd);

//printf("%f x\n", obj->polygonals[0].normal.x);

	//printf("%f y\n", obj->polygonals[0].normal.y);

		//printf("%f z\n", obj->polygonals[0].normal.z);
   data->objnbr = data->obj->num_polygonals;
    return (data);

}