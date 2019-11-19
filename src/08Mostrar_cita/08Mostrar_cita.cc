
bool Mostrar_cita(string Nombre,string Apellidos)
{
	list<Citas>::iterator itC;
	for(it=citas_.begin();it!=citas_.end(),it++)
	{
		if((strcmp(it->getNombre()Nombre)==0)&&(strcmp(it->getApellidos()==Apellidos)==0))
		{
			cout<<it->getNombre()<<"|"<<it->getApellidos()<<"|"<<it->getTelefono()<<"|"<<it->getCorreo()<<"|"<<it->getDireccion()<<"\n";
			cout<<"Fecha: "<<it->getFecha()<<"\n";
			
		}
	}
}
