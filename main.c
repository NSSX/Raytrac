 #include "my_h.h"

void give_effect(t_env *e)
{
  e->effect.vec = give_vec(e->obj_tmp, e);
  e->effect.shadow = give_shadow(e);
  e->effect.light = my_light(e);
  e->effect.bri = light_effect(e);
  e->effect.light = mult_value(&(e->effect.light), e->effect.shadow);
  e->effect.bri = a_x_b(&(e->effect.bri), &(e->effect.light));
}

void    all_effect(t_env *e)
{
  give_effect(e);
  //brillance
  e->color = plus(&(e->color), &(e->effect.bri));
  limit_for_vec(&(e->color), 0, 1);
  e->color = a_x_b(&(e->color), &(e->effect.light));
}

int             expose_hook(t_env *e)
{
  ray_tracer(e);
  return (1);
}
//REGARDE TJRS DANS LA DIRECTION
int event_mlx(int keycode, t_env *e)
{
  static int etat;

  if(!etat)
    etat = 3;
  if(keycode == 65307)
       exit(1);
   if(keycode == 65362)
     {
       //       e->eye_dir.y += 5;
       e->v2 += 0.2;
     }
  if(keycode == 65363)
    {
      //fleche droite;
      e->v += 0.2;
//      e->eye_dir.x -= 5;    
    }
  if(keycode == 65364)
    {
      e->v2 -= 0.2;
      // e->eye_dir.y -= 5;
    }
  if(keycode == 65361)
    {
            e->v -= 0.2;
      //    e->eye_dir.x += 5;
    }
  if(keycode == 100)
    {
      e->v += M_PI / 2;
      //droite
    }
    if(keycode == 97)
      {
        e->v -= M_PI / 2;
      }
  if(keycode == 119)
    { 
      double val;
      double a = cos(e->v);
      double b = sin(e->v);
      double val1 = a * 5;
      double val2 = b * 5;
      if(val1 > 5)
	val1 = 5;
      else if(val1 < -5)
	val1 = -5;
      if(val2 > 5)
	val2 = 5;
      else if(val2 < -5)
	val2 = -5;
      e->eye_pos.z -= val1;//a * 5;
      e->eye_pos.x += val2;//b * 5;
      printf("ZZZZ %f XXXXX %f\n", val1 ,val2);

      /*      if(a < 0)
	a = -a;
      if(b < 0)
	b = -b;
      if(a>=b)
	val = a;
      else
	val = b;
      if(cos(e->v) >= 0 && sin(e->v) >= 0)
	{
	  printf("P  P\n");
	  val = cos(e->v) - sin(e->v);
	  if(val < 0)
            val = -val;
	  printf("VAL %f\n",val);
	  printf("EYE_ZZZZ = %f\n",val * 5);    
	  e->eye_pos.z -= val * 5;
	  val = 1-val;
	  printf("EYE_XXX = %f\n",val * 5);    
	  e->eye_pos.x += val * 5;
	}
      else if(cos(e->v) < 0 && sin(e->v) >= 0)
	{
	  printf("N  P\n");
	  val = cos(e->v) - sin(e->v);
	  if(val < 0)
	    val = -val;
	  if(val > 1)
	    val = 2 - val;
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.x += val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.z += val * 5;
	}
      else if(cos(e->v) < 0 && sin(e->v) < 0)
	{
	  printf("N  N\n");
	  val = cos(e->v) - sin(e->v);
	  if(val < 0)
            val = -val;
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.x -= val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.z += val * 5;
	}
      else if(cos(e->v) >= 0 && sin(e->v) < 0)
	{
	  printf("P  N\n");
	  val = cos(e->v) - sin(e->v);
	  if(val < 0)
            val = -val;
	  if(val > 1)
	    val = 2 - val;
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.z -= val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.x -= val * 5;
	  }*/
    }  
  if(keycode == 115)
    {     
      double val;
      double a = cos(e->v);
      double b = sin(e->v);
      double val1 = a * 5;
      double val2 = b * 5;
      if(val1 > 5)
        val1 = 5;
      else if(val1 < -5)
        val1 = -5;
      if(val2 > 5)
        val2 = 5;
      else if(val2 < -5)
        val2 = -5;
      e->eye_pos.z += val1;//a * 5;                                                                                  
      e->eye_pos.x -= val2;//b * 5;                                                                                  
      printf("ZZZZ %f XXXXX %f\n", val1 ,val2);


       /*      if(a < 0)
        a = -a;
      if(b < 0)
        b = -b;
      if(a>=b)
        val = a;
      else
        val = b;
      if(cos(e->v) >= 0 && sin(e->v) >= 0)
        {
          val = cos(e->v) - sin(e->v);
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.z += val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.x -= val * 5;
        }
      else if(cos(e->v) < 0 && sin(e->v) >= 0)
        {
          val = cos(e->v) - sin(e->v);
          if(val < 0)
            val = -val;
          if(val > 1)
            val = 2 - val;
          printf("ENCULLLLLER");
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.z -= val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.x -= val * 5;
        }
      else if(cos(e->v) < 0 && sin(e->v) < 0)
        {
          val = cos(e->v) - sin(e->v);
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.x += val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.z -= val * 5;
        }
      else if(cos(e->v) >= 0 && sin(e->v) < 0)
        {
          val = cos(e->v) - sin(e->v);
          if(val > 1)
            val = 2 - val;
          printf("VAL %f\n",val);
          printf("EYE_ZZZZ = %f\n",val * 5);
          e->eye_pos.z += val * 5;
          val = 1-val;
          printf("EYE_XXX = %f\n",val * 5);
          e->eye_pos.x += val * 5;
	  }*/
    } 
  if(keycode == 44)
    {
      t_obj   *obj;

      obj = e->obj;
      while (obj)
	{
	  if (obj->type == etat)
	    {
	      obj->rot.z += 5;
	    }
	  obj = obj->next;
	}
    }
  if(keycode == 46)
    {
      t_obj   *obj;

      obj = e->obj;
      while (obj)
        {
	      if (obj->type == etat)
		{
		  obj->rot.z -= 5;
		}
          obj = obj->next;
        }
    }
  if(keycode == 39)
    {
      t_obj   *obj;

      obj = e->obj;
      while (obj)
        {
          if (obj->type == etat)
            {
              obj->rot.x -= 5;
            }
          obj = obj->next;
        }
    }
  if(keycode == 47)
    {
      t_obj   *obj;

      obj = e->obj;
      while (obj)
        {
          if (obj->type == etat)
            {
              obj->rot.x += 5;
            }
          obj = obj->next;
        }
    }
  if(keycode == 32)
    {
      if(etat == 3)
	etat = 1;
      else
	etat++;
      printf("%d\n",etat);
    }
  //  double val = cos(e->v) - sin(e->v);
  //  printf("val FIN  %f\n",val);
    printf("cos %f sin %f\n",cos(e->v),sin(e->v));
 printf("\n----------------\n\n");
 
 ray_tracer(e);
  return(1);
}

int main(int ac, char **av)
{
  t_env e;

  give(&e);
  parsing(&e, ac, av[1]);
  init_eye(&e);
  light_number(&e);
  pov(&e);
  e.v = 0;
  e.v2 = 0;
  e.win =  mlx_new_window(e.mlx, e.width, e.height, e.name);
  e.nl = 1 / e.nl;
  e.v = e.eye_dir.x * 0.2;
  e.v2 = e.eye_dir.y * 0.2;
  mlx_expose_hook(e.win, expose_hook, &e);;
  mlx_key_hook(e.win, event_mlx, &e);
  mlx_loop(e.mlx);
  return(0);
}
